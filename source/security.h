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
 
#define MBED_DOMAIN "9df3e043-3315-41c7-ba13-c87fce45b6ef"
#define MBED_ENDPOINT_NAME "28f45df8-40e8-485a-8c60-9f1aa55e9648"
 
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
"MIIBzzCCAXOgAwIBAgIEGunikzAMBggqhkjOPQQDAgUAMDkxCzAJBgNVBAYTAkZ\r\n"
"JMQwwCgYDVQQKDANBUk0xHDAaBgNVBAMME21iZWQtY29ubmVjdG9yLTIwMTYwHh\r\n"
"cNMTUxMTA1MTg0MjQxWhcNMTYxMjMxMDYwMDAwWjCBoTFSMFAGA1UEAxNJOWRmM\r\n"
"2UwNDMtMzMxNS00MWM3LWJhMTMtYzg3ZmNlNDViNmVmLzI4ZjQ1ZGY4LTQwZTgt\r\n"
"NDg1YS04YzYwLTlmMWFhNTVlOTY0ODEMMAoGA1UECxMDQVJNMRIwEAYDVQQKEwl\r\n"
"tYmVkIHVzZXIxDTALBgNVBAcTBE91bHUxDTALBgNVBAgTBE91bHUxCzAJBgNVBA\r\n"
"YTAkZJMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAE9BM/7iBTkk8n7hBUY1aAe\r\n"
"oDSg+0XP9V0sm/NUkpL0w6wZb5XKV5sJx2SKn9bu3xu/kecrW884d5whP/3pyXs\r\n"
"QDAMBggqhkjOPQQDAgUAA0gAMEUCIAnJ5fo3xqzLUhvCvdLOWbXaLmCQs/rDg3D\r\n"
"Smo08zCBrAiEA55KO1mlUAywVBG+XoWoiIOgyjCJ0s8ZNqBYy9vuGQCU=\r\n"
"-----END CERTIFICATE-----\r\n";
 
const uint8_t KEY[] = "-----BEGIN PRIVATE KEY-----\r\n"
"MIGHAgEAMBMGByqGSM49AgEGCCqGSM49AwEHBG0wawIBAQQg2yKR3/UHR5HiaI1b\r\n"
"/tB8y+0eJPTmzCIXHSnT17SgPyihRANCAAT0Ez/uIFOSTyfuEFRjVoB6gNKD7Rc/\r\n"
"1XSyb81SSkvTDrBlvlcpXmwnHZIqf1u7fG7+R5ytbzzh3nCE//enJexA\r\n"
"-----END PRIVATE KEY-----\r\n";
 
#endif //__SECURITY_H__
