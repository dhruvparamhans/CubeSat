class mag_sensor:
    ##Class for retrieving raw data from the the magnetometers, giving the
    ##magnetic field measured on the 3 axes
    ##Modes: Active and Passive (to define)
    ##Functions:
    ##1. Initialization of the class
    ##2. get data
    def __init__(self):
        self.state = False;
        self.data_raw = []
        self.temperature = 0
    def get_mag(self):
        ##Retrieve raw data from the sun sensors
        ##Insert code here
        if self.state == False:
            ##Insert code which gets data from the sensors+temperature
            return (self.temperature, self.data_raw)
        else:
            return (0,0)

class mag_vector(mag_sensor):
    ##From the raw magnetometer data, calculates the temperature
    ##corrected magnetic field
    def __init__(self,mag_sensor):
        self.mag_sensor = mag_sensor
        self.data_mag = []
    def calc_mag_vector(self):
        ##Insert code for calculating sun_vector here
        return self.data_mag