class sun_sensor:
    ##Class for retrieving raw data from the the sun sensors on each of the
    ##five faces
    ##Modes: Active and Passive (to define)
    ##Functions:
    ##1. Initialization of the class
    ##2. get data
    ##Serial Port initialization
    def __init__(self):
        self.state = False;
        self.data_raw = [] ## stores the raw data, 5 faces=5 elements
        ##Sun sensor always active. False when we need to switch it off
        ##due to energy constraints

    def get_sun(self):
        ##Retrieve raw data from the sun sensors
        ##Insert code here
        ##Code only for testing functionality and inheritance
        if self.state == False:
            return [4,4]
        else:
            return [3,3]
##In the final version of the code, this class will not be present here
##Present here just for testing purposes
class albedo:
    ##This class retrieves the albedo data from the on-board albedo map using
    ##the position data retrieved from the GPS.
    def __init__(self, file, shadow):
        self.data_albedo = []
        self.data_pos = position
        self.shadow = False
    def get_alb(self, position, time):
        ##insert code for calculating albedo at a given position
        position=orbitography.get_position()
        inShadow=shadow.inShadow(position,time)

        if self.shadow == False:
            return self.data_albedo
        else:
            return []

##Position class present here just for testing purposes
##The position class shall eventually be placed with the GPS class
##Refer to class structure.jpg for details.
class position:
    def __init__(self):
        self.data_pos = []

class orbitography:
    ##2 Positions 2 Times
    ##Harcoded Orbit (characteristic of the orbit exig?)
    def __init__self(self):
        self.pos_calc = []
        ##Orbit Parameters
        ##Orbit last calculated
        ##Expected orbit characteristics shall be hard-coded here
    def set_orbit(self,inclinaison,altitude,LTDN):
        ##Reset orbit using data from the ODB
        ##LTDN: Local time descending node
        ##Capable of resetting the orbital paramters.

    ##def get_position(time):
      ##  return



class sun_vector:
    ##From the raw sun sensor data, calculates the vector from the satellite
    ##to the sun. Also tells if satellite is in earth shadow or not
    ##Just the one function: get sun_vector
    def __init__(self,sun_sensor,albedo):
        self.sun_sensor = sun_sensor
        self.state = self.sun_sensor.state
        self.albedo = albedo
        self.data_sun = []
    def calc_sun_vector(self):
        position

        inShadow=shadow.inShadow()
        albedo_value=albedo.get_albedo()
        sun_sensor_value=sun_sensor.get_sun_sensor()
        if self.albedo.get_alb == []:
            return []
        else:
            data_albedo = self.albedo.get_alb()
        data_raw =  self.sun_sensor.get_sun()
        ##Insert code for calculating sun_vector here
        print "It works"
        return self.data_sun


##Testing for inheritance
test_sun = sun_sensor()
test_pos = position()
test_alb = albedo(test_pos)
test_alb.shadow = True
test_sun_vector = sun_vector(test_sun,test_alb)
print test_sun_vector.calc_sun_vector()