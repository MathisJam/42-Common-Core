/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.cpp										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mjameau <mjameau@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/03/31 10:55:36 by mjameau		   #+#	#+#			 */
/*   Updated: 2025/04/11 10:07:21 by mjameau		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"
#include "../inc/Base.hpp"
#include <cstdlib>
#include <ctime>

static Base *generate(void)
{

	switch (rand() % 3)
	{
		case 0:
			std::cout << BOLD GREEN << "GENERATE FUNCTION : " << RESET BOLD << "Created A" << std::endl;
			return (new A());
			break;
		case 1:
			std::cout << BOLD GREEN << "GENERATE FUNCTION : " << RESET BOLD << "Created B" << std::endl;
			return (new B());
			break;
		case 2:
			std::cout << BOLD GREEN << "GENERATE FUNCTION : " << RESET BOLD << "Created C" << std::endl;
			return(new C());
			break;
		default:
			std::cerr << BOLD RED << "Error at generate function" << RESET << std::endl;
			return (NULL);
	}
}

static void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << BOLD << "Is type A pointer" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << BOLD << "Is type B pointer" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << BOLD << "Is type C pointer" << std::endl;
	else
		std::cerr << BOLD RED << "Unknown pointer type" << RESET << std::endl;
}

static void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "Is type A reference" << std::endl;
		return;
	} catch (...) {}

	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "Is type B reference" << std::endl;
		return;
	} catch (...) { }

	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "Is type C reference" << std::endl;
		return;
	} catch (...) {}

	std::cout << BOLD RED << "Unknown type" << RESET << std::endl;
}


int main()
{
	// std::srand(std::time(NULL)); // UNCOMMENT TO CHANGE SEED FOR RAND() % 3 IN GENERATE
	int tests = 10;

	for (int i = 0; i < tests; ++i)
	{
		std::cout << BOLD MAGENTA << "\n\t\t\t--- Test " << i + 1 << " ---" << RESET << std::endl;
		Base *obj = generate();
		if (!obj)
			return 1;

		if (obj)
		{
			identify(obj);
			identify(*obj);
			delete obj;
		}
		else
			std::cerr << BOLD RED << "Generation failed!" << RESET << std::endl;
	}

	std::cout << BOLD MAGENTA << "\n\t\t\t--- Test ERROR " << " ---" << RESET << std::endl;

	Base *obj = NULL;
	identify(obj);

	return 0;
}
