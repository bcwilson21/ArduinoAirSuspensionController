#include "screen.h"

extern float g_gpsSpeedMph;
extern uint8_t g_gpsSatellites;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void drawsplashscreen()
{
    for (int i = -display.height(); i <= 0; i += 2)
    {
        display.clearDisplay();
        display.drawBitmap(0, i, logo_bmp_bootimg, 128, 64, 1);
        display.display();
        delay(1); // 1 ms
    }
    delay(3500); // 2 seconds

    for (int i = 0; i <= 64; i += 2)
    {
        display.clearDisplay();
        display.drawBitmap(0, i, logo_bmp_bootimg, 128, 64, 1);
        display.display();
        delay(1);
    }
}

void drawPSIReadings()
{
    display.clearDisplay();

    display.drawBitmap(0, 0, logo_bmp_corvette, 128, 20, 1);

    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);

    int textHeightPx = 10;
    int secondRowXPos = SCREEN_WIDTH / 2;
    int thirdsSecondRowXPos = SCREEN_WIDTH / 3 - 1;
    int thirdsThirdRowXPos = SCREEN_WIDTH / 3 * 2.2 + 2;

    // Front
    display.setCursor(20, 2 * textHeightPx + 5);
    display.print(int(getWheel(WHEEL_FRONT_DRIVER)->getSelectedInputValue())); // front driver

    display.setCursor(secondRowXPos - 15, 2 * textHeightPx + 5);
    display.print(F(" -F-   "));

    int frontPassengerValue = int(getWheel(WHEEL_FRONT_PASSENGER)->getSelectedInputValue());
    String fpStr = String(frontPassengerValue);
    int fpMaxDigits = 3; // change this if you expect more digits
    int fpSpaceCount = fpMaxDigits - fpStr.length();

    String fpPaddedStr = "";
    for (int i = 0; i < fpSpaceCount; i++) {
    fpPaddedStr += " ";
}
    fpPaddedStr += fpStr;

    display.print(fpPaddedStr); // front passenger

    // Rear
    display.setCursor(20, 3.5 * textHeightPx + 5);
    display.print(int(getWheel(WHEEL_REAR_DRIVER)->getSelectedInputValue())); // rear driver

    display.setCursor(secondRowXPos - 15, 3.5 * textHeightPx + 5);
    display.print(F(" -R-   "));

    int rearPassengerValue = int(getWheel(WHEEL_REAR_PASSENGER)->getSelectedInputValue());
    String rpStr = String(rearPassengerValue);
    int rpMaxDigits = 3; // change this if you expect more digits
    int rpSpaceCount = rpMaxDigits - rpStr.length();

    String rpPaddedStr = "";
    for (int i = 0; i < rpSpaceCount; i++) {
    rpPaddedStr += " ";
}
    rpPaddedStr += rpStr;

    display.print(rpPaddedStr); // rear passenger

    // Tank Data
    display.setCursor(0, 5 * textHeightPx + 5);
    display.print(F("T: "));
    display.print(int(getCompressor()->getTankPressure()));

    // GPS Data
    display.setCursor(thirdsSecondRowXPos, 5 * textHeightPx + 5);
    display.print(F("MPH: "));
    display.print(g_gpsSpeedMph, 1); // 1 decimal point

    display.setCursor(thirdsThirdRowXPos, 5 * textHeightPx + 5);
    display.print(F("SC: "));
    display.print(g_gpsSatellites);

    display.display();
}


