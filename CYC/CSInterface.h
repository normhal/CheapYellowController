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
#ifndef CSINTERFACE_H
#define CSINTERFACE_H

void receiveCMD();
/*
 ***************************************************
 * Parse Data received from the Command Station
 * This code is intended to grow as more integration 
 * with the Command Station is included
 ***************************************************
*/
void parse(char *com);

#endif
