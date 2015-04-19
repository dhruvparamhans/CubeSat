class GPS:
    def __init__(self):
        self.pos = [] ##Position data
        self.vel = [] ##Velocity data
        self.lat = 0 ##Latitude
        self.long = 0 ##Longitude
        self.alt = 0 ##Altitude
    def gps_reading(self):
        ##Insert code for getting data from the GPS
        return 0
    def position(self):
        return GPS.pos
    def velocity(self):
        return GPS.vel
    def latlong(self):
        return (GPS.lat, GPS.long, GPS.alt)









