// =====================================================================================
// 
//       Filename:  Main.cpp
// 
//    Description:  Driver program for application
// 
//        Version:  1.0
//        Created:  02/28/2014 03:04:02 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  David P. Riedel (dpr), driedel@cox.net
//        License:  GNU General Public License v3
//        Company:  
// 
// =====================================================================================

	/* This file is part of CollectEDGARData. */

	/* CollectEDGARData is free software: you can redistribute it and/or modify */
	/* it under the terms of the GNU General Public License as published by */
	/* the Free Software Foundation, either version 3 of the License, or */
	/* (at your option) any later version. */

	/* CollectEDGARData is distributed in the hope that it will be useful, */
	/* but WITHOUT ANY WARRANTY; without even the implied warranty of */
	/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
	/* GNU General Public License for more details. */

	/* You should have received a copy of the GNU General Public License */
	/* along with CollectEDGARData.  If not, see <http://www.gnu.org/licenses/>. */


#include <iostream>

#include "CollectEDGARApp.h"

int main(int argc, char** argv)
{
	//	help to optimize c++ stream I/O (may screw up threaded I/O though)
	
	std::ios_base::sync_with_stdio(false);

	int result = 0;
	try
	{
		CollectEDGARApp myApp{argc, argv};
		myApp.StartUp();
		myApp.Run();
		myApp.Quit();
	}
	
	catch (std::exception& theProblem)
	{
		CApplication::sCErrorHandler->HandleException(theProblem);
		result = 3;
	}
	catch (...)
	{		// handle exception: unspecified
		std::cerr << "Something completely unexpected happended.  Processing stopped.\n";
		result = 6;
	}

	return result;
}
