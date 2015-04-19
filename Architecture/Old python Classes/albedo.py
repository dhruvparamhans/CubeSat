class albedo:
    def __init__(self):
        self.albedo = "Default"
    def get_albedo(self):
        current_position = orbitography.get_position()
        shadow = orbitography.in_shadow()
        ##Insert code for calculating albedo


