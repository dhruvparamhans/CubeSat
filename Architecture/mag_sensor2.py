class mag_sensor:
    def __init__(self):
        self.mag_field_raw = []
        self.temperature = 0
    def get_sensor_data(self):
        ##Insert code to get sensor data
        return (self.mag_field_raw, self.temperature)

class mag_vector:
    def __init__(self):
        self.B_vector = []
    def get_magvector(self):
        sensor_data = mag_sensor.get_sensor_data()
        ##Insert code to calculate the magnetic field from raw data
        return self.B_vector

class igrf:
    def __init__(self):
        self.field = []
    def get_magfield_terre(self,position):
        ##Insert code to get terrestrial magnetic field at a given position
        return self.field



