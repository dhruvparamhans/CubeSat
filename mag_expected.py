##Position class present here just for testing purposes
##The position class shall eventually be placed with the GPS class
##Refer to class structure.jpg for details.
class position:
    def __init__(self):
        self.data_pos = []

##IGRF class will not be present here in the final version
##Refer to the class structure.jpg for details
class igrf:
    def __init__(self,position):
        self.mag_ref = []
        self.data_pos = position
    def get_mag_ref(self):
        ##Insert code for retrieving magnetic field data from the on-board
        ##magnetic field map
        return mag_ref

class mag_expected:
    def __init__(self, igrf):
        self.igrf = igrf
        igrf.position = position
        self.data_mag_exp = []
    def treat_data(self):
        ##Insert code here for calculating expected mag data
        return data_mag_exp

