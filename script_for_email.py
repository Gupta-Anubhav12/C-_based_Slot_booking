import smtplib
from email.message import EmailMessage
msg = EmailMessage()
msg['Subject'] = 'From my script'
msg['From'] = 'environmentseekersnitj@gmail.com'
msg['To'] = 'anubhavgupta2260@gmail.com'
smtp = smtplib.SMTP_SSL('smtp.gmail.com', 465)
smtp.login('environmentseekersnitj@gmail.com', 'fdgphlhigarggaoy')
msg.set_content('You are booked :: Dermatologist SLOT4 Saturday')
smtp.send_message(msg)
smtp.quit()