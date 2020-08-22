# MDP-Sensor-Piecewise-Function-Generator
Help you generate the if-else so you don't have to find the m and c in the y=mx+c for the piecewise function.

Usage:
1. Connect IR sensor to pin A0. (If your sensor is connected to other pins other than A0, open sensor_piecewise.ino and edit Line 1. 
2. Run `sensor_piecewise.ino` to get the raw value of your sensor at the various interval and fill up the excel sheet in root folder. 
3. Once excel sheet is filled, proceed to run `GenerateConvertToCM.py` (Make sure pandas is available in your python environment) and enter the excel sheet's file name. The piecewise function will be generated. 
4. Copy the generated function into `sensor_piecewise.ino`, comment out the first line and uncomment out the second line in `void loop()`, run the code and check the readings again.

Note(s):
1. Any empty rows in excel sheet will be dropped. 


Example output from `GenerateConvertToCM.py`:
```
double convertToCM(double val){
        int dist;
        if(val>587)
                dist=5;
        else if(val<=587&&val>393)      //5cm to 10.0cm
                dist=(val-781.0)/-38.8;
        else if(val<=393&&val>305)      //10.0cm to 15.0cm
                dist=(val-569.0)/-17.6;
        else if(val<=305&&val>277)      //15.0cm to 20.0cm
                dist=(val-389.0)/-5.6;
        else if(val<=277&&val>273)      //20.0cm to 25.0cm
                dist=(val-293.0)/-0.8;
        else
                dist=25.0;
        return dist;
}
```
