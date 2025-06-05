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
#ifndef EDIT_LOCO_PAGE_H
#define EDIT_LOCO_PAGE_H

static void function_name_cb(lv_event_t * e);

static void fname_cb(lv_event_t * e);

void setupFuncEditSlots();

void action_fedit_slot(lv_event_t * e);

void action_fclear_slot(lv_event_t * e);

void action_edit_loco_button(lv_event_t * e);

static void chkbox_event_cb(lv_event_t * e);

#endif
