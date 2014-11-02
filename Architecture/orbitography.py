class orbitography:
    def __init__(self, altitude = "Default altitude",
    inclinaison = "Default Inclinaison", params = "Default Parameters"):
        self.altitude = altitude
        self.inclinaison = inclinaison
        self.params = params
        ##Default orbit parameters stored here
        ##

    def set_orbit(self, parameters):
        gps_data = gps.get_data()
        ##Reset orbital parameters using GPS data
