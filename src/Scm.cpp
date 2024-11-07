//       _________ __                 __
//      /   _____//  |_____________ _/  |______     ____  __ __  ______
//      \_____  \\   __\_  __ \__  \\   __\__  \   / ___\|  |  \/  ___/
//      /        \|  |  |  | \// __ \|  |  / __ \_/ /_/  >  |  /\___ |
//     /_______  /|__|  |__|  (____  /__| (____  /\___  /|____//____  >
//             \/                  \/          \//_____/            \/
//  ______________________                           ______________________
//                        T H E   W A R   B E G I N S
//         Stratagus - A free fantasy real time strategy game engine
//
/**@name Scm.cpp - The scm. */
//
//      (c) Copyright 2002-2007 by Jimmy Salmon
//
//      This program is free software; you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation; version 2 dated June, 1991.
//
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//
//      You should have received a copy of the GNU General Public License
//      along with this program; if not, write to the Free Software
//      Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
//      02111-1307, USA.
//
//	$Id$
//@{
// Lcoal
#include "Scm.h"
#include "Chk.h"
#include "Hurricane.h"
#include "endian.h"
#include "FileUtil.h"
#include "platform.h"

// System
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string>
#include <vector>
#include <string>

using namespace std;

Scm::Scm(std::shared_ptr<Hurricane> hurricane, const std::string &arcfile, Storage storage) :
  Converter(hurricane)
{
  string arcfile_scm = arcfile + ".scm";
  m_scm_path = storage(arcfile_scm).getFullPath();

  bool result = mHurricane->extractFile(arcfile_scm, m_scm_path); // TODO maybe the Breeze extractFile interface is broken????
  assert(result);
  if (result)
  {
    m_storm = make_shared<Storm>(m_scm_path);

    // create the Chk files that will be deleted together with Scm
    chk = make_shared<Chk>(m_storm, arcfile);
  }
}

Scm::~Scm()
{
  // delete the temporary .chk file
  //platform::unlink(m_scm_path);
}


