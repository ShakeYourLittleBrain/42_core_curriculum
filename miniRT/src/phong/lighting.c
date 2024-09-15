/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 23:58:43 by mohrahma          #+#    #+#             */
/*   Updated: 2024/07/26 04:30:20 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

/*---------------------------------------------------------------------------*/
//									Specular Lighting
/*---------------------------------------------------------------------------*/
// Specular lighting represents the shiny, mirror-like highlights on a surface
// where light is reflected in a concentrated beam. This component is
// responsible for the bright spots of light seen on shiny surfaces and depends
// on the angle between the reflected light direction and the viewer's
// direction.
//
//							The Specular Lighting Formula:
//					I_specular = I_light ⋅ K_s ⋅ (max(0, R ⋅ V))^α
//
// - I_specular = is the specular lighting component.
// - I_light = is the intensity of the light source.
// - K_s = is the specular reflection coefficient (material property).
// - R = is the normalized reflection vector.
// - V = is the normalized view direction vector (from the surface point to the
//			viewer).
// - α = is the shininess exponent, which controls the size and sharpness of
//       the specular highlight.
//
// max(0, R ⋅ V) ensures that only light reflecting towards the viewer
// (where the angle between R and V is less than 90 degrees) contributes
// to the specular lighting.
/*---------------------------------------------------------------------------*/
static t_color	ft_specular(t_light *light, t_vector intersection_point,
		t_vector intersection_normal, t_vector viewpoint)
{
	t_vector	light_direction;
	t_vector	reflection;
	t_color		specular;
	float		specular_intensity;

	light_direction = vector_normalisation(vector_subtraction(\
	light->cord_vector, intersection_point));
	reflection = vector_subtraction(vector_multiplication(intersection_normal, 2
				* dot_product(intersection_normal, light_direction)),
			light_direction);
	specular_intensity = pow(fmax(dot_product(viewpoint, reflection), 0.0f),
			32);
	specular.red = specular_intensity * light->color.red * light->brightness;
	specular.green = specular_intensity * light->color.green
		* light->brightness;
	specular.blue = specular_intensity * light->color.blue * light->brightness;
	return (specular);
}

/*---------------------------------------------------------------------------*/
// 								Diffuse Lighting
/*---------------------------------------------------------------------------*/
// In the Phong model, the diffuse component represents the light that is
// scattered in many directions when it hits a rough surface. The amount of
// light reflected depends on the angle between the light source and the
// surface normal.
//
//							The Diffuse Lighting Formula:
//                  I_diffuse = I_light ⋅ K_d ⋅ max(0, L ⋅ N)
//
//	- I_diffuse = is the diffuse lighting component.
//	- I_light = is the intensity of the light source.
//	- K_d = is the diffuse reflection coefficient (material property).
//	- L = is the normalized light direction vector from the surface point to
//			the light source.
//	- N = is the normalized surface normal vector at the point being shaded.
//	- L ⋅ N = is the dot product between the light direction and the normal
//				vector, which gives the cosine of the angle between them.
//
// The max(0, ...) function ensures that only light coming from in front of the
// surface (where the angle is less than 90 degrees) contributes to the
// diffuse lighting.
/*---------------------------------------------------------------------------*/

static t_color	ft_diffuse(t_light *light, t_vector intersection_point,
		t_vector intersection_normal)
{
	t_vector	light_direction;
	t_color		diffuse;
	float		diffuse_intensity;

	light_direction = vector_normalisation(vector_subtraction(\
	light->cord_vector, intersection_point));
	diffuse_intensity = fmax(dot_product(intersection_normal, light_direction),
			0.0f);
	diffuse.red = diffuse_intensity * light->color.red * light->brightness;
	diffuse.green = diffuse_intensity * light->color.green * light->brightness;
	diffuse.blue = diffuse_intensity * light->color.blue * light->brightness;
	return (diffuse);
}

t_color	ft_light(t_miniRT **miniRT, t_vector intersection_point,
		t_vector intersection_normal, t_color object_color)
{
	t_vector	viewpoint;
	t_color		result;
	t_color		diffuse;
	t_color		specular;

	(void)object_color;
	viewpoint = vector_normalisation(vector_subtraction(\
	(*miniRT)->camera->cord_vector, intersection_point));
	diffuse = ft_diffuse((*miniRT)->light, intersection_point,
			intersection_normal);
	specular = ft_specular((*miniRT)->light, intersection_point, \
	intersection_normal, viewpoint);
	result.red = diffuse.red + specular.red;
	result.green = diffuse.green + specular.green;
	result.blue = diffuse.blue + specular.blue;
	return (result);
}
