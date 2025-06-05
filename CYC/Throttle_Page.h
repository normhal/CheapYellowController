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
#ifndef THROTTLE_PAGE_H
#define THROTTLE_PAGE_H


void populateThrottle();

void clearGuest();

void populateLocoDetails();

static void throttle_selection_handler_cb(lv_event_t * e);

static void functions_cb(lv_event_t * e);

void dd_locos_cb(lv_event_t * e);

void setSpeed(uint16_t locoAddr, uint16_t newSpeed, uint8_t newDir);

void action_throttle_button(lv_event_t * e);

#endif
