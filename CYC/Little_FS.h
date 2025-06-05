/* 
 *****************************************************************************************************************************
 *  COPYRIGHT (c) 2025 Norman Halland (NormHal@gmail.com) unless otherwise noted.
 *
 *  This program and all its associated modules is free software:
 *  you can redistribute it and/or modify it under the terms of the
 *  GNU General Public License as published by the Free Software
 *  Foundation, either version 3 of the License, or (at your option)
 *  any later version.
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see http://www.gnu.org/licenses
 *
 *****************************************************************************************************************************
*/
/*

 *   By Ross Scanlon iam@rosscoe.com

*/
#include <LittleFS.h>

#ifndef LITTLE_FS_H
#define LITTLE_FS_H


void listDir(fs::FS &fs, const char *dirname, uint8_t levels);

/****************************************************************************************************************
  Parser Routine which loads the Accessory file from LittleFS
****************************************************************************************************************/
/*
void populateAccArray(const char *path);
*/

//****************************************************************************************************************
//  Parser Routine which loads the Locos file from LittleFS
//****************************************************************************************************************
void populateLocoArray(const char *path);

//****************************************************************************************************************
//  Parser Routine which loads the Function file from LittleFS and populates the related Locos
//****************************************************************************************************************

void populateLocoFunctions(const char *path);

/*
****************************************************************************************************************
  Parser Routine which loads the Routes Array from LittleFS
  ID, Acc1,State1, Acc2,State2, Acc3,State3, Acc4,State4, Acc5,State5, Acc6,State6
 States :- Closed = 0, Thrown = 1
****************************************************************************************************************
*/
/*
void populateRoutesArray(const char *path);
*/

//****************************************************************************************************************
//  Parser Routine which loads the Credentials Array from LittleFS
//****************************************************************************************************************
void populateCredentials(const char *path);

//****************************************************************************************************************
//  Parser Routine which loads the Selected Throttle IDs Array from LittleFS
//****************************************************************************************************************
void populateSelected(const char *path);

//
//****************************************************************************************************************
// File Saving Routines
//  1. Create empty work file                     eg. work.txt
//  2. Construct delimited record from array
//  3. Write all valid records
//  4. Delete work file and Exit if ANY error
//  5. Delete Oldest File
//  6. Rename Backup file to become Oldest        eg. locos.old -> locos.saf
//  7. Rename existing file to become new Backup  eg. locos.txt -> locos.old
//  8. Rename newly created work file             eg. work.txt -> locos.txt
//  9. Reverse above 3 steps if any Error
//  10. clear "Dirty" Flag
//  11. close file
//****************************************************************************************************************
//
void saveLittleFS();

//
//*********************************************************************************************
//
//*********************************************************************************************
//
void saveLocos(fs::FS &fs, const char * path, const char * message);

//
//*********************************************************************************************
//
//*********************************************************************************************
//
void renameFile(fs::FS &fs, const char * path1, const char * path2);

//
//*********************************************************************************************
//
//*********************************************************************************************
//
void deleteFile(fs::FS &fs, const char * path);

//
//****************************************************************************************************************
// Save Loco Functions
//****************************************************************************************************************
//
void saveFunctions(fs::FS &fs, const char * path, const char * message);

//
//****************************************************************************************************************
// Throttles are stored in a multi-dimensional Array "SelectedIDs"
// SelectedIDs has four first level elements (0,1,2, &3) 
// each having 10 LocoIDs
// An unoccupied element contains "255" - ie a LocoID of 0 is invalid
//****************************************************************************************************************
//
void saveThrottles(fs::FS &fs, const char * path, const char * message);

//
//****************************************************************************************************************
// Save all Accessories
//****************************************************************************************************************
//
/*
void saveAccessories(fs::FS &fs, const char * path, const char * message);
*/

//
//****************************************************************************************************************
// Save All Routes
//****************************************************************************************************************
//
/*
void saveRoutes(fs::FS &fs, const char * path, const char * message);
*/

//
//****************************************************************************************************************
// ToDo
//****************************************************************************************************************
//
void saveCredentials(fs::FS &fs, const char * path, const char * message);

/*
//
//****************************************************************************************************************
//
//****************************************************************************************************************
//
*/
void restoreLittleFS();

#endif
