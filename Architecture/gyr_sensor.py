class gyr_sensor:
    def __init__(self):
        self.data_gyr_raw = []
    def get_gyr(self):
        ##Insert code here to get the gyroscope data
        return data_gyr_raw

##If ever we need to treat the raw data from the gyrometer sensors
class gyr_vector:
    def __init__(self, gyr_sensor):
        self.gyr_sensor = gyr_sensor
        self.data_gyr_final = []
    def treat_gyr_data(self):
        ##Insert code for treatment of raw gyr data
        return self.data_gyr_final





