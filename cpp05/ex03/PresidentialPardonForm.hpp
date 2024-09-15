/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 11:56:38 by skhastag          #+#    #+#             */
/*   Updated: 2024/09/01 20:59:47 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <iostream>
# include <string>

class PresidentialPardonForm : public AForm
{
  private:
	std::string _target;

  public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	~PresidentialPardonForm();

	PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);

	virtual void action() const;
	static AForm *create(const std::string &target);
};

#endif
