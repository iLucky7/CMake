/*=========================================================================

  Program:   CMake - Cross-Platform Makefile Generator
  Module:    $RCSfile$
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) 2002 Kitware, Inc., Insight Consortium.  All rights reserved.
  See Copyright.txt or http://www.cmake.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef cmLinkDirectoriesCommand_h
#define cmLinkDirectoriesCommand_h

#include "cmStandardIncludes.h"
#include "cmCommand.h"

/** \class cmLinkDirectoriesCommand
 * \brief Define a list of directories containing files to link.
 *
 * cmLinkDirectoriesCommand is used to specify a list
 * of directories containing files to link into executable(s). 
 * Note that the command supports the use of CMake built-in variables 
 * such as CMAKE_BINARY_DIR and CMAKE_SOURCE_DIR.
 */
class cmLinkDirectoriesCommand : public cmCommand
{
public:
  /**
   * This is a virtual constructor for the command.
   */
  virtual cmCommand* Clone() 
    {
    return new cmLinkDirectoriesCommand;
    }

  /**
   * This is called when the command is first encountered in
   * the CMakeLists.txt file.
   */
  virtual bool InitialPass(std::vector<std::string> const& args);

  /**
   * This determines if the command gets propagated down
   * to makefiles located in subdirectories.
   */
  virtual bool IsInherited() { return true;  }

  /**
   * The name of the command as specified in CMakeList.txt.
   */
  virtual const char* GetName() { return "LINK_DIRECTORIES";}

  /**
   * Succinct documentation.
   */
  virtual const char* GetTerseDocumentation() 
    {
    return "Specify directories in which to search for libraries.";
    }
  
  /**
   * More documentation.
   */
  virtual const char* GetFullDocumentation()
    {
    return
      "  LINK_DIRECTORIES(directory1 directory2 ...)\n"
      "Specify the paths in which the linker should search for libraries.";
    }
  
  cmTypeMacro(cmLinkDirectoriesCommand, cmCommand);
};



#endif
