# Raspberry Pi Pico W Wi-Fi Anslutning

Detta projekt demonstrerar hur man ansluter en Raspberry Pi Pico W till Wi-Fi med hjälp av Cyw43-drivrutinen för Wi-Fi-funktionalitet.

## Förutsättningar

Innan du börjar, säkerställ att du har följande:

- Raspberry Pi Pico W
- En dator med Docker installerad (för utvecklingsmiljö)
- En micro-USB-kabel för att ansluta Pico W till datorn
- Wi-Fi nätverksuppgifter (SSID och lösenord)
- Grundläggande förståelse för C-programmering och användning av kommandoraden

## Komma igång

### 1. Installera Utvecklingsmiljö

1. Klona repositoryt till din lokala maskin:

    ```bash
    git clone https://github.com/gulcoder/pico-wifi.git
    cd pico-wifi
    ```

2. Bygg projektet i Docker eller använd din lokala utvecklingsmiljö:

    - Använd Docker:
        - Starta Docker Desktop och öppna terminalen.
        - Kör kommandot `docker build -t pico-wifi .`
        
    Eller använd en lokal utvecklingsmiljö för att bygga projektet direkt på din dator.

### 2. Kompilera och ladda upp

1. Efter att ha byggt projektet med CMake, anslut din Raspberry Pi Pico W via USB till datorn.
2. Skriv ut filen `wifi.uf2` till din Pico W genom att kopiera den till enheten som dyker upp som en USB-enhet.
3. Starta om din Pico W genom att ta bort och återansluta USB-kabeln.

### 3. Kontrollera anslutningen

När du har laddat upp koden kommer Pico W att försöka ansluta till Wi-Fi. Om anslutningen lyckas kommer en IP-adress att skrivas ut på skärmen, som kan användas för att pinga Pico W:

```bash
ping 192.168.x.x
