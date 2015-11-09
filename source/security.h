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
 
//#define MBED_DOMAIN "decd06cc-2a32-4e5e-80d0-7a7c65b90e6e"
//#define MBED_ENDPOINT_NAME "099a77cc-c9a1-4ed0-990a-7e2140656dea"

#define MBED_DOMAIN         "domain"
#define MBED_ENDPOINT_NAME  "dougs-cool-endpoint"
 
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
"MIIBzjCCAXOgAwIBAgIEZenBXDAMBggqhkjOPQQDAgUAMDkxCzAJBgNVBAYTAkZ\r\n"
"JMQwwCgYDVQQKDANBUk0xHDAaBgNVBAMME21iZWQtY29ubmVjdG9yLTIwMTYwHh\r\n"
"cNMTUxMTA4MDIwNzQ1WhcNMTYxMjMxMDYwMDAwWjCBoTFSMFAGA1UEAxNJZGVjZ\r\n"
"DA2Y2MtMmEzMi00ZTVlLTgwZDAtN2E3YzY1YjkwZTZlLzA5OWE3N2NjLWM5YTEt\r\n"
"NGVkMC05OTBhLTdlMjE0MDY1NmRlYTEMMAoGA1UECxMDQVJNMRIwEAYDVQQKEwl\r\n"
"tYmVkIHVzZXIxDTALBgNVBAcTBE91bHUxDTALBgNVBAgTBE91bHUxCzAJBgNVBA\r\n"
"YTAkZJMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEuWyPrVL35khjDpQM152EG\r\n"
"K+YQSE9kkBQP1URDk5vw+FDBXkc6QipBKhVM/Ot7+mdix+qTYnB4d5H17pw9TVn\r\n"
"ODAMBggqhkjOPQQDAgUAA0cAMEQCIB+o3v/vZsZt3lzbQ2ZOz6WRgL45yIV4F0j\r\n"
"5RfO8f5lPAiBNCd1RPl8Z3ZFoxI4JFfmwkpo3PPrPljbmkRQTVumKDQ==\r\n"
"-----END CERTIFICATE-----\r\n";
 
const uint8_t KEY[] = "-----BEGIN PRIVATE KEY-----\r\n"
"MIGHAgEAMBMGByqGSM49AgEGCCqGSM49AwEHBG0wawIBAQQgXgF1Ucx14fmZhoS7\r\n"
"2SQchPg77qXrrhLoJhg4ai2RhZ6hRANCAAS5bI+tUvfmSGMOlAzXnYQYr5hBIT2S\r\n"
"QFA/VREOTm/D4UMFeRzpCKkEqFUz863v6Z2LH6pNicHh3kfXunD1NWc4\r\n"
"-----END PRIVATE KEY-----\r\n";
 
#endif //__SECURITY_H__