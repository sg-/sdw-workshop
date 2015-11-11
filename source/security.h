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

// Use for your IoTF Connector 
//#define MBED_DOMAIN "decd06cc-2a32-4e5e-80d0-7a7c65b90e6e"
//#define MBED_ENDPOINT_NAME "2504666a-7627-4ec9-80b0-883d0286426f"

// Use for QuickStart
#define MBED_DOMAIN "domain"
#define MBED_ENDPOINT_NAME "change-me"
 
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
"MIIBzzCCAXOgAwIBAgIEcL+KNjAMBggqhkjOPQQDAgUAMDkxCzAJBgNVBAYTAkZ\r\n"
"JMQwwCgYDVQQKDANBUk0xHDAaBgNVBAMME21iZWQtY29ubmVjdG9yLTIwMTYwHh\r\n"
"cNMTUxMTEwMDE1OTI2WhcNMTYxMjMxMDYwMDAwWjCBoTFSMFAGA1UEAxNJZGVjZ\r\n"
"DA2Y2MtMmEzMi00ZTVlLTgwZDAtN2E3YzY1YjkwZTZlLzI1MDQ2NjZhLTc2Mjct\r\n"
"NGVjOS04MGIwLTg4M2QwMjg2NDI2ZjEMMAoGA1UECxMDQVJNMRIwEAYDVQQKEwl\r\n"
"tYmVkIHVzZXIxDTALBgNVBAcTBE91bHUxDTALBgNVBAgTBE91bHUxCzAJBgNVBA\r\n"
"YTAkZJMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEnXUQfgfcjomKTGCxwk17k\r\n"
"vCJQ3F0DduankFABwP/d8P6MzGTlHUf+a9RUXtbzxSPlNosG6gDqTxkyrxgoLbU\r\n"
"ITAMBggqhkjOPQQDAgUAA0gAMEUCIQDrQwAEKC9jwFY7+1tEX11mxHaEgA8zMs2\r\n"
"oHA/P34mtHQIgRn3Sv9B2iyAbijq+SxovrpCJ9SE96d12eq5HM+pR6LE=\r\n"
"-----END CERTIFICATE-----\r\n";
 
const uint8_t KEY[] = "-----BEGIN PRIVATE KEY-----\r\n"
"MIGHAgEAMBMGByqGSM49AgEGCCqGSM49AwEHBG0wawIBAQQgDpqMJArbNhHUvN7z\r\n"
"BgOgxkPVdfRtd0IFB17wtTT+QYShRANCAASddRB+B9yOiYpMYLHCTXuS8IlDcXQN\r\n"
"25qeQUAHA/93w/ozMZOUdR/5r1FRe1vPFI+U2iwbqAOpPGTKvGCgttQh\r\n"
"-----END PRIVATE KEY-----\r\n";
 
#endif //__SECURITY_H__