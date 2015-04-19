class sun_sensor:
    def __init__(self):
        self.sun_data_raw = []
    def get_data(self):
        ##Gets data from each of the 5 sun sensors on board
        return self.sun_data_raw

class shadow:
    def __init__(self):
        self.shad = False
    def is_shadow(self, position, time):
        ##Insert code to calculate whether in shadow or not
        return self.shad

class albedo:
    def __init__(self):
        self.alb = 0;
    def getalbedo(self,position,shadow):
        ##Insert code to calculate albedo given the time, position and shadow
        return self.alb

class sun_vector:
    def __init__(self):
        self.sun_vect = [] ##3-component vector
    def get_sunvector(self):
        time = rtc.get_time()
        position = orbitography.get_position()
        in_shadow = shadow.is_shadow(position,time)
        if in_shadow == True:
            return []
        else:
            sensor_data = sun_sensor.get_data()
            albedo_value = albedo.getalbedo(position,in_shadow)
            ##Insert code to calculate sun vector
            return sun_vect


