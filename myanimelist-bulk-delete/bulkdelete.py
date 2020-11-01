from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import time


def main():
    user = input('Enter your user name: ')
    key = input('Enter your password: ')
    section = int(input(
                    'Which section of anime do you want to delete? Enter the corresponding number:\n'
                    '1. Currently Watching\n'
                    '2. Completed\n'
                    '3. On Hold\n'
                    '4. Dropped\n'
                    '5. Plan to Watch\n'
                    '6. All Anime\n'))

    choice = section
    if choice == 5 or choice == 6:
        choice += 1

    number = int(input('How many anime do you have in the selected section?\n'))

    driver = webdriver.Chrome()
    driver.get('https://myanimelist.net/login.php')

    username = driver.find_element_by_name('user_name')
    password = driver.find_element_by_name('password')

    username.send_keys(user)
    username.send_keys(Keys.TAB)
    password.send_keys(key)
    password.send_keys(Keys.ENTER)

    for x in range(1, number + 1):
        driver.get('https://myanimelist.net/animelist/' + user + '?status=' + str(choice))
        time.sleep(1)
        anime = driver.find_elements_by_class_name('List_LightBox')
        link = anime[1].get_attribute('href')
        driver.get(link)
        delete = driver.find_element_by_id('delete-form')
        delete.submit()
        print('Deleted ' + str(x) + ' anime.')

    driver.quit()
    print('\nOperation Successful.')

main()
