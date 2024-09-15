/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:32:10 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/06 19:51:52 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

# define IDEAS 100

class Brain
{
	private:
		std::string _ideas[IDEAS];
	public:
		Brain();
		Brain(const Brain& copy);
		~Brain();

		Brain& operator=(const Brain& copy);

		void setIdea(const std::string& idea, int index);
		const std::string& getIdea(int index) const;
};

#endif
