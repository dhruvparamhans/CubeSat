class attitude_determination:
    def __init__(self):
        #7-component list, first 4 for the quaternion,3 for velocity
        self.attitude =[]
    def get_attitude(self):
        sun_vect = sun_vector.get_sunvector()
        mag_vect = mag_vector.get_magvector()
        gyr_vect = gyr_vector.get_gyrvector()
        position = orbitographie.get_position()
        ##write code for determining the atttitude
        return self.atttiude

class detumbling:
    def __init__(self):
        self.couple = []
        ##Couple to be generated in each of the theree bobines
    def get_couple_dtumb():
        position = orbitography.get_position()
        attitude = attitude_determination.get_attitude()
        field_terre = igrf.get_magfield_terre(position)
        ##Insert B_dot algorithm
        return self.couple

class attitude_control:
    def __init__(self):
        self.couple = []
        ##Couple to be generated in each of the three bobines
    def get_couple_attcont():
        positio = orbitography.get_position()
        attitude = attitude_determination.get_attitude()
        field_terre = igrf.get_magfield_terre(position)
        ##Insert LQR algorihm
        return self.couple




