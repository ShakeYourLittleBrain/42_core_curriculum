/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedForWinners.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 05:30:40 by skhastag          #+#    #+#             */
/*   Updated: 2024/07/30 06:53:48 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEDFORWINNERS_HPP
# define SEDFORWINNERS_HPP

# include <iostream>
# include <string>
# include <fstream> // for file I/O

class SedForWinners
{
	private:
		std::string	_filename;
		std::string	_fileContent;
		std::ifstream	_file;

	public:
		SedForWinners(std::string filename);
		~SedForWinners( void );
		void	readfileToContent( void );
		void	replaceStringInContent( const std::string& s1, const std::string& s2 );
		void	writeContentToFile( void );
};

#endif
