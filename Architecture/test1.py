class sun_vector:
    ##Functions for sun_sensor class
    ## 1. get_data: Requests data from the sun_sensors at each of the five faces. Returns a list data_sun
    ## 2. treat_data: Using data_sun and the map of the albedo, returns a list sun_vector
    ## Auxiliary functions: Functions to help in calculating sun_vectoe.  
    ## 1. get_albedo: Retrieve the albedo from the Albedo map using the latitude 
    ## 2. get_position: Retrieve the position of the satellite to be used for get_albedo

    def __init__(self, state, sun_sensor, position, albedo)
    def __init__(self,MODE_ODB, MODE_ADCS):
        ##MODE_ODB defines whether the ADCS is on or off
        ##MODE_ADCS defines whether the ADCS is in Control Mode or Attitude Determination mode
        ##MODE_ODB = 0 ==> ADCS off, 1 ==> ADCS on 
        ##MODE_ADCS = 0 ==> Control Mode, 1 ==> Attitude Determination Mode
        self.MODE_ODB = MODE_ODB
        self.MODE_ADCS = MODE_ADCS
        self.data_sun = [] ##List of 5 elements which stores the raw data from each of the 5 sun sensors
        self.data_position = [] ##List of 3 elements which stores the current position of the satellite
        self.albedo = 0
        self.sun_vector = [] ##List of 3 elements which stores the vector from the satellite pointing towards the sun    
    def get_data(self):
        ##Ask for data from sun sensors
        ##Insert code here
        if self.MODE_ODB == 1 & self.MODE_ADCS == 1:
                        return [0,0]
        else:
            return self.data_sun
    def get_position(self):
        ##Ask for position either from ADCS itself or via GPS
        ##Insert code here
        return self.data_position
    def get_albedo(self,data_position):
        ##Retrieves albedo using current position and on-board albedo map
        ##Insert code here
        return self.albedo
    def treat_data(self,albedo):
        ##Calculates the sun_vector using albedo 
        ##Insert code here. 
        return self.sun_vector

    def get_sun_vector(self):
            position=self.position.get_position()
            raw_data
            albedo_data

            
            

##Testing the class 
test1 = sun_sensor(0,0)
test2 = sun_sensor(1,1)
test3 = sun_sensor(1,0)

## Class Structure





