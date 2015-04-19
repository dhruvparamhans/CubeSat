class interface:
    def __init__(self):
        self.current = []
        ##Current to be provided to the bobines
    def get_current(self, mode):
        if mode == "Detumbling":
            field_requis = attitude_control.get_couple_attcont()
        else:
            field_requis = detumbling.get_couple_dtumb()
        ##Insert code to calculate the current to be sent to the bobines
        return self.current
    def send_current(self):
        ##Insert code to send the current to each of the bobines
