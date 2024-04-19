class WeekDayError(Exception):
    pass
	
class Weeker:
    mydays = ['mon', 'tue', 'wed', 'thur', 'fri', 'sat', 'sun']

    def __init__(self, day):
        try:
            self.current_day = Weeker.mydays.index(day)
        except:
            raise WeekDayError


    def __str__(self):
        return Weeker.mydays[self.current_day]

    def add_days(self, n):
        self.current_day = (self.current_day + n) % 7

    def subtract_days(self, n):
        self.current_day = (self.current_day - n) % 7


try:
    weekday = Weeker('mon')
    print(weekday)
    weekday.add_days(15)
    print(weekday)
    weekday.subtract_days(23)
    print(weekday)
    weekday = Weeker('Monday')
except WeekDayError:
    print("Sorry, I can't serve your request.")
    