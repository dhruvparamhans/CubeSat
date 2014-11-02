
##Name your functions on the basis of the service provided and not by how we
##calculate the eventual vector

class gyr_sensor:
    def __init__(self):
        self.serial....
    def get_gyr(self):
        ##Insert code here to get the gyroscope data
        data=
        return data_gyr_raw

##If ever we need to treat the raw data from the gyrometer sensors
##Temperature Calibrated  data
class gyr_vector:
    def __init__(self, gyr_sensor):
        self.gyr_sensor = gyr_sensor
        self.data_gyr_final = []
    def get_vector(self):
        ##Insert code for correction (or not) of the raw GPS Data
        return data_gyr_final






