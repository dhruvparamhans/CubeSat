class gyr_sensor:
    def __init__(self):
        self.gyr_data_raw = []
        self.temperature = 0
    def get_gyr_data(self):
        ##Insert code to get the raw data
        return (self.gyr_data_raw, self.temperature)

class gyr_vector:
    def __init__(self):
        self.gyr_vect = []
    def get_gyr_vector(self):
        ##Insert code for eventual calibration of the raw gyroscope data
        return self.gyr_vect

