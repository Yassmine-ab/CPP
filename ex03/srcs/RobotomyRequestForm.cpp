#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), _target("default")
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm for target " << _target << " created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), _target(other._target)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destroyed" << std::endl;
}

const std::string& RobotomyRequestForm::getTarget() const
{
	return (_target);
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	checkExecutable(executor);
	performRobotomy();
}

void RobotomyRequestForm::performRobotomy() const
{
	std::cout << "BZZZZZZT! WHIRRRR! DRILLING NOISES!" << std::endl;
	
	// génère des nombres aléatoires
	srand(time(NULL));
	
	// 50% de chance de succès
	if (rand() % 2 == 0)
		std::cout << "✅ " << _target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "❌ Robotomy of " << _target << " failed!" << std::endl;
}