/*
 *  Arduino SD Card Tutorial Example
 *
 *  by Dejan Nedelkovski, www.HowToMechatronics.com
 */

#include <SD.h>
#include <SPI.h>

File myFile;

void setup() {
	Serial.begin(9600);
	// SD Card Initialization
	if (SD.begin())
	{
		Serial.println("SD card is ready to use.");
		SD.remove("test.txt");
	}
	else
	{
		Serial.println("SD card initialization failed");
		return;
	}
}
void loop() {
	// Create/Open file 
	myFile = SD.open("test.txt", FILE_WRITE);

	// if the file opened okay, write to it:
	if (myFile) {
		//Serial.println("Writing to file...");
		// Write to file
		myFile.print("01");
		myFile.print("\t");
		myFile.print("B1");
		myFile.print("\t");
		myFile.println("1.38");
		myFile.close(); // close the file
		//Serial.println("Done.");
	}
	// if the file didn't open, print an error:
	else {
		Serial.println("error opening test.txt");
	}

	// Reading the file
	myFile = SD.open("test.txt");
	if (myFile) {
		//Serial.println("Read:");
		// Reading the whole file
		while (myFile.available()) {
			Serial.write(myFile.read());
		}
		myFile.close();
	}
	else {
		Serial.println("error opening test.txt");
	}
	delay(1000);
}