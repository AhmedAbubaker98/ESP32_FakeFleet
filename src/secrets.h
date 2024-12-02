#include <pgmspace.h>

#define SECRET
#define THINGNAME "ESP32Thing"

const char WIFI_SSID[] = "ZAIN5G_79F747";
const char WIFI_PASSWORD[] = "cW44yMr7";
const char AWS_IOT_ENDPOINT[] = "a3gn1ihz2gofe6-ats.iot.us-east-1.amazonaws.com";

// Amazon Root CA 1
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
)EOF";

// Device Certificate
static const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWjCCAkKgAwIBAgIVAPOLI+36Qj7b/0uaM+po/PkketsoMA0GCSqGSIb3DQEB
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0yNDExMzAxNjQ5
MzRaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDRhF6QzHgzYZ5mPY6C
DHzQ0JjqNampz5ua2/MRyGn93FtA1/1CAoY4l0hiaFcLzICuFTFx8TVhRbjv/beb
RxLT33Q+z/FAVIjLz6IwkFW0GIWKtZtla+BYWUDjwf8ep1TKTqiSAEB3HU+v6ImQ
9ZxsM9dvUO5pfQNypliOLgdlki/vUsVBEU4YMyQ5JHrh0/4sZ1rZ5csyXJ5gGhiI
Hpzxia/rgrMleNWP+22bfKMTZh2iW4NeDr1yuGBUW44qTJQmg62h6Tw3XD4lSQkf
TdmGHGwPuTQcPEcMjjag8Mh/ZDJQ01q/XqLIhtCBRI3Sg0nxsgKRRPtq2Ex0b1wt
0CqtAgMBAAGjYDBeMB8GA1UdIwQYMBaAFDl/einn+9E9L4hGpREUzpFIocl1MB0G
A1UdDgQWBBQWNH+Zjb7O6puDf2bGKq/Eb2izSDAMBgNVHRMBAf8EAjAAMA4GA1Ud
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEAIScX5MDnjAUfm5Hl0+KUV+D3
zVE+3VsUVAjgAZpRrJ172wBLDbCEmiz3jGnqI6JmYhKmbOetGLpig/nXw3HRl2IQ
ditkNkdyftur4gF+wtNnTc4U0Z/9iED75rK90y7DHPsQPZeUttFQ/dxx5n/947Gu
V/Od5414HjCqjCFy4j+4/XNRGF3dGbmOQOSablOLaZXzlOldkBItRax7TXjGY3NA
YQo8BPTOs0foQjQ2oh96504wQv4PaX1nfjpYuKRT2VwRg8Sdc4P59XwTQ6PCB7UE
SdHXpf9ohX+Z2+bzYVUpo+FkC8XW3wCtSxEuTCoXRqc7lzvvNr5Eyc/R4Y/b4w==
-----END CERTIFICATE-----
)KEY";

// Device Private Key
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEowIBAAKCAQEA0YRekMx4M2GeZj2Oggx80NCY6jWpqc+bmtvzEchp/dxbQNf9
QgKGOJdIYmhXC8yArhUxcfE1YUW47/23m0cS0990Ps/xQFSIy8+iMJBVtBiFirWb
ZWvgWFlA48H/HqdUyk6okgBAdx1Pr+iJkPWcbDPXb1DuaX0DcqZYji4HZZIv71LF
QRFOGDMkOSR64dP+LGda2eXLMlyeYBoYiB6c8Ymv64KzJXjVj/ttm3yjE2YdoluD
Xg69crhgVFuOKkyUJoOtoek8N1w+JUkJH03ZhhxsD7k0HDxHDI42oPDIf2QyUNNa
v16iyIbQgUSN0oNJ8bICkUT7athMdG9cLdAqrQIDAQABAoIBABh9DECIZZQ72LPC
hiGVLBGMEBNv6kC6z0kuZB6z+g997fyKQkOw39dFd2RpJaNvZ6rxNzJGKyMPbyo9
0XQIvp6dA41D6MLIHqUTw7VBaYL/SryHtX4JOdOZuwfj6NnAXRy4TOOju+UwO9wn
pcyXqIzNEmUkZHlX70s7PiaAIsUwNtGSxnfw7VxnvgFW15HJCJEN77qKuvz0rcl+
miQWaXcg8xMlQIxsrohjxIqcetGZyQm05zktb4naVIwXw87ZiGfcg2pPuua4HU1Y
OIJ+3Fvx+D4pr+WmzxSG2qm9eKfWWD3q9jo84MWEji33SMoHmkBa2pAd+91fmVoS
dFqoQwECgYEA8dbb8Ac2J6CcdmWX983X9pBDiqO7qj0qb47lR+lf9EaQ+EW5T16U
0qPrQiPvQ8rQq/rI5+C1TLg6FFvpSlzwkhq2/2OtLIB8VdxZor1RbzeIaLqnbJRD
mBkB/M0iZMdMVxO73cwW/RAK9IUz2/B1LGHjdHpWE2PJQZZ8BnTZqnECgYEA3ckB
DuK3R7WUdaTdoFVVpsE4PYwKILNvla3mwdNDWkdujQACv9PREEEkMN5Rs9WY9xXt
vz8qXEyLc3WPz9AfNTMSOBujwfascHUiANPnVPUzfRyXZFyRdPSvrbWW9yBDs4bG
35EwBNJfqaLZyxrbTp/Py1mfO5mXcK0py7ngyf0CgYAT48Xm8dDkZXM40ZY0DTvr
zWWgq2Kt16X70tbMmUcJAhy+Lo3VF0RKJq0cnXP6MV4EJvYLDBIdIzGzpvOC6C3o
9kWCr6H4fQC81wiQN93QtdKEOoW2imMcyUG+luhzPWjr6HWVAkoJuh4Mij//oMEi
S1K3q7AUnCpbOJMuvMGCIQKBgQDERNZf4vjJSALKnYzYD8yNlt57cQuhZsnvzwaw
LpKjOSW3N/Q26G9SECPD72qkV/lXaBuOrIqDReX+1mHfSVHk1X5hEuy3gOGXX8Eo
tF47DAd1x7CeS2EZ/FPfyRyBNBdVr4cdYDH7gmTQDWLp36mGidztGzHUH5cqSsP7
G1K3zQKBgEEyZ1PtfdipqVbLIbqhBZ9QC6dsldq+aHj1RvK/yA3NZ1za8vNfudYn
cZbv69hyjYsxCE+DG366NGMNcsQIikDSeVCagnODulo4t8IXo/3LEyN99HC/8lfy
soRFriLLtWE5zR1d2PQxoeq9/3S5DwkZ74Q6DMQqIkmuK1Wl7MC5
-----END RSA PRIVATE KEY-----
)KEY";
