class sun_vector:
    ##From the raw sun sensor data, calculates the vector from the satellite
    ##to the sun. Also tells if satellite is in earth shadow or not
    ##Just the one function: get sun_vector
    def __init__(self):
        self.sun_vector =[]
        self.shadow = False
    def sun_vector(self):
        raw_data = sun_sensor.get_data
        albedo_data = albedo.get_data
        position = self.position.get_position
        ##Enter Code Here
        return (sun_vector, shaow)
