/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 05:35:11 by skhastag          #+#    #+#             */
/*   Updated: 2024/08/13 07:26:37 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) :
	_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &copy) :
	_name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &copy) {
	if (this != &copy) {
		_isSigned = copy._isSigned;
	}
	return *this;
}

const std::string &AForm::getName() const {
	return _name;
}

bool AForm::getIsSigned() const {
	return _isSigned;
}

int AForm::getGradeToSign() const {
	return _gradeToSign;
}

int AForm::getGradeToExecute() const {
	return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() >= _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

void AForm::execute(const Bureaucrat &executor) const {
	if (!_isSigned)
		throw IsNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
	this->action();
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
	os << "AForm: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No") << ", Grade to Sign: " << form.getGradeToSign() << ", Grade to Execute: " << form.getGradeToExecute();
	return os;
}

