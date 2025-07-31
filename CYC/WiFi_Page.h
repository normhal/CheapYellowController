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

#ifndef WIFI_PAGE_H
#define WIFI_PAGE_H

void action_wifi_button(lv_event_t * e);
/*
 ********************************************************************************************************
 * Call-Back routine for WiFi Dropdown
 ********************************************************************************************************
*/
void dd_cb(lv_event_t * e);
/*
 ********************************************************************************************************
 * Handler for a Selected SSID from the list
 ********************************************************************************************************
*/
static void ssid_selected(lv_event_t * e);

void connectWiFi();

#endif // WIFI_PAGE_H
