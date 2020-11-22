# MDP-Sensor-Piecewise-Function-Generator
Help you generate the if-else so you don't have to find the m and c in the y=mx+c for the piecewise function.

### Usage:
1) Connect IR sensor to Analog Pins. (If you wish to only calibrate specific sensor, open sensor_piecewise.ino and comment out lines for other sensors) 
2) Upload and run `sensor_piecewise.ino`, and open Serial Monitor to get the raw value of your sensor at the various interval and fill up the excel sheet in root folder. (1 Excel Sheet per Sensor)
3) Once excel sheet is filled, proceed to run `GenerateConvertToCM.py` (Make sure pandas is available in your python environment) and enter the excel sheet's file name. The piecewise function will be generated. 
4) Copy the generated function into `sensor_piecewise.ino`, comment out the first line and uncomment out the second line in `void loop()`, run the code and check the readings again.

### Ways to use the codes:
1) Have 1 function declared for each sensor (rename the produced function name to indicate which sensor it's for; frontLeftConvertToCM(), frontRightConvertToCM() for example.)
2) Have a massive function, then have another argument to specify which sensor is it for, then use a switch case to call the respective if-else chunk. (i.e. you will be only using the if-else-return chunk of the code generated)

Note(s):
1. Any empty rows in excel sheet will be dropped. 


Example output from `GenerateConvertToCM.py`:
```
double convertToCM(double val){
        int dist;
        if(val>657) dist=3;
        else if(val<=657&&val>552) dist=(val-814.5)/-52.5; //3cm to 5.0cm
        else if(val<=552&&val>380) dist=(val-724.0)/-34.4; //5.0cm to 10.0cm
        else if(val<=380&&val>295) dist=(val-550.0)/-17.0; //10.0cm to 15.0cm
        else if(val<=295&&val>247) dist=(val-439.0)/-9.6; //15.0cm to 20.0cm
        else if(val<=247&&val>218) dist=(val-363.0)/-5.8; //20.0cm to 25.0cm
        else if(val<=218&&val>209) dist=(val-263.0)/-1.8; //25.0cm to 30.0cm
        else dist=30.0;
        return dist;
}
```
