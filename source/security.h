/*
 * Copyright (c) 2015 ARM Limited. All rights reserved.
 * SPDX-License-Identifier: Apache-2.0
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef __SECURITY_H__
#define __SECURITY_H__
 
#include <inttypes.h>

#ifdef USE_QUICKSTART
    #define MBED_DOMAIN "domain"
    #define MBED_ENDPOINT_NAME "dougs-excellent-endpoint"
#else
    #define MBED_DOMAIN "decd06cc-2a32-4e5e-80d0-7a7c65b90e6e"
    #define MBED_ENDPOINT_NAME "7097a999-377a-46b4-b771-1a5e4e4fc5da"
#endif

const uint8_t SERVER_CERT[] = "-----BEGIN CERTIFICATE-----\r\n"
"MIIBmDCCAT6gAwIBAgIEVUCA0jAKBggqhkjOPQQDAjBLMQswCQYDVQQGEwJGSTEN\r\n"
"MAsGA1UEBwwET3VsdTEMMAoGA1UECgwDQVJNMQwwCgYDVQQLDANJb1QxETAPBgNV\r\n"
"BAMMCEFSTSBtYmVkMB4XDTE1MDQyOTA2NTc0OFoXDTE4MDQyOTA2NTc0OFowSzEL\r\n"
"MAkGA1UEBhMCRkkxDTALBgNVBAcMBE91bHUxDDAKBgNVBAoMA0FSTTEMMAoGA1UE\r\n"
"CwwDSW9UMREwDwYDVQQDDAhBUk0gbWJlZDBZMBMGByqGSM49AgEGCCqGSM49AwEH\r\n"
"A0IABLuAyLSk0mA3awgFR5mw2RHth47tRUO44q/RdzFZnLsAsd18Esxd5LCpcT9w\r\n"
"0tvNfBv4xJxGw0wcYrPDDb8/rjujEDAOMAwGA1UdEwQFMAMBAf8wCgYIKoZIzj0E\r\n"
"AwIDSAAwRQIhAPAonEAkwixlJiyYRQQWpXtkMZax+VlEiS201BG0PpAzAiBh2RsD\r\n"
"NxLKWwf4O7D6JasGBYf9+ZLwl0iaRjTjytO+Kw==\r\n"
"-----END CERTIFICATE-----\r\n";
 
const uint8_t CERT[] = "-----BEGIN CERTIFICATE-----\r\n"
"MIIB0DCCAXOgAwIBAgIEH2j9dTAMBggqhkjOPQQDAgUAMDkxCzAJBgNVBAYTAkZ\r\n"
"JMQwwCgYDVQQKDANBUk0xHDAaBgNVBAMME21iZWQtY29ubmVjdG9yLTIwMTYwHh\r\n"
"cNMTUxMTExMDQ1OTQ4WhcNMTYxMjMxMDYwMDAwWjCBoTFSMFAGA1UEAxNJZGVjZ\r\n"
"DA2Y2MtMmEzMi00ZTVlLTgwZDAtN2E3YzY1YjkwZTZlLzcwOTdhOTk5LTM3N2Et\r\n"
"NDZiNC1iNzcxLTFhNWU0ZTRmYzVkYTEMMAoGA1UECxMDQVJNMRIwEAYDVQQKEwl\r\n"
"tYmVkIHVzZXIxDTALBgNVBAcTBE91bHUxDTALBgNVBAgTBE91bHUxCzAJBgNVBA\r\n"
"YTAkZJMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAERh5IZoB14UtXZPsHAJGyF\r\n"
"gR/O17SCc/WW9NFXzvOes7IQFs/bcSORfXMlgIdLuyLWUoe/01/97q5ru+VPegH\r\n"
"iDAMBggqhkjOPQQDAgUAA0kAMEYCIQDgdM7bVGpn6uf37ZkGAjukINp6QAr5sPe\r\n"
"r/KprvO+s7QIhANfzJDb2cfg1DmP9D8jpPNShB95aBpw+AzQutXdWPm9H\r\n"
"-----END CERTIFICATE-----\r\n";
 
const uint8_t KEY[] = "-----BEGIN PRIVATE KEY-----\r\n"
"MIGHAgEAMBMGByqGSM49AgEGCCqGSM49AwEHBG0wawIBAQQgKNDK7v5vJxsJIT/D\r\n"
"04/QKqmm7m08Fmy3uY/dNIxeHpWhRANCAARGHkhmgHXhS1dk+wcAkbIWBH87XtIJ\r\n"
"z9Zb00VfO856zshAWz9txI5F9cyWAh0u7ItZSh7/TX/3urmu75U96AeI\r\n"
"-----END PRIVATE KEY-----\r\n";
 
#endif //__SECURITY_H__