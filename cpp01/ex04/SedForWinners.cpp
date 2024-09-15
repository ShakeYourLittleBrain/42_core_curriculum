/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedForWinners.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 05:31:07 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/01 01:17:49 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedForWinners.hpp"

/*
	The constructor opens the file with the given filename.
	If the file cannot be opened,
	the constructor prints an error message and exits the program.
*/
SedForWinners::SedForWinners(std::string filename) : _filename(filename)
{
	this->_file.open(_filename);
	if (!this->_file.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		exit(EXIT_FAILURE);
	}
}

/*
	The destructor also close the file.
*/

SedForWinners::~SedForWinners(void)
{
	this->_file.close();
}

/*
	This function reads the content of the file into the file content string.
	It uses a loop to read the file line by line and appends each line to the file content string.
	The loop continues until the end of the file is reached.
*/

void SedForWinners::readfileToContent(void)
{
	std::string line;
	while (std::getline(_file, line))
	{
		this->_fileContent += (line + '\n');
	}
}

/*
	This function replaces all occurrences of s1 with s2 in the file content.
	It uses a loop to find all occurrences of s1 and replace them with s2.
	The loop continues until no more occurrences of s1 are found.
	The loop uses the find method(because it is forbidden to use replace) of std::string to find
	the next occurrence of s1.
	The loop uses the append method of std::string to append non-matching parts of the file content.
	I use reserve to minimize reallocations of the new content string.(this is great for performance)
	I use swap to efficiently replace the file content with the new content.(this is great for performance)
	Note that the function does not modify the file content directly. Instead,
		it creates a new string
	with the replaced content and then swaps it with the original content.
	Finally,
		the function appends the rest of the file content to the new content string and swaps it
	with the original content.
*/

void SedForWinners::replaceStringInContent(const std::string &s1,
	const std::string &s2)
{
	size_t	startPos;
	size_t	foundPos;

	std::string newContent;
	newContent.reserve(this->_fileContent.length());
	startPos = 0;
	foundPos = this->_fileContent.find(s1, startPos);
	while (foundPos != std::string::npos)
	{
		newContent.append(this->_fileContent, startPos, foundPos - startPos);
		newContent.append(s2);
		startPos = foundPos + s1.length();
		foundPos = this->_fileContent.find(s1, startPos);
	}
	newContent.append(this->_fileContent, startPos);
	this->_fileContent.swap(newContent);
}

/*
	This function writes the content of the file to a new file with the same name as the original
	file but with the .winners extension.
	It uses the ofstream class to create a new file with the given name and write the content of the file to it.
	At the end it closes the new file.
*/

void SedForWinners::writeContentToFile(void)
{
	std::ofstream newFile(this->_filename + ".winners");
	newFile << this->_fileContent;
	newFile.close();
}

