#!/usr/bin/python3
"""
    User Model
"""
import hashlib
import uuid


class User:
    """
    User class:
    - id: public string unique (uuid)
    - password: private string hash in MD5
    """
    __password = None

    def __init__(self):
        """
        Initialize a new user:
        - assigned an unique `id`
        """
        self.id = str(uuid.uuid4())

    @property
    def password(self):
        """
        Password getter
        """
        return self.__password

    @password.setter
    def password(self, pwd):
        """
        Password setter:
        - `None` if `pwd` is `None`
        - `None` if `pwd` is not a string
        - Hash `pwd` in MD5 before assign to `__password`
        """
        if pwd is None or not isinstance(pwd, str):
            self.__password = None
        else:
            self.__password = hashlib.md5(pwd.encode()).hexdigest().lower()

    def is_valid_password(self, pwd):
        """
        Valid password:
        - `False` if `pwd` is `None`
        - `False` if `pwd` is not a string
        - `False` if `__password` is `None`
        - Compare `__password` and the MD5 value of `pwd`
        """
        if pwd is None or not isinstance(pwd, str) or self.__password is None:
            return False
        return hashlib.md5(pwd.encode()).hexdigest().lower() == self.__password


if __name__ == '__main__':
    user_1 = User()
    user_2 = User()

    u_pwd = "myPassword"
    user_1.password = u_pwd
    user_2.password = None
    user_2.password = 89

    print("Test User")
    print("New User should have an id" if user_1.id is None else "OK: User has id")
    print("User.id should be unique" if user_1.id == user_2.id else "OK: IDs are unique")
    print("User.password should be hashed" if user_1.password == u_pwd else "OK: Password is hashed")
    print("User.password should be None by default" if user_2.password is not None else "OK: Password is None by default")
    print("User.password should be None if setter to None" if user_2.password is not None else "OK: Password is None when set to None")
    print("User.password should be None if setter to an integer" if user_2.password is not None else "OK: Password is None when set to integer")
    print("is_valid_password should return True if it's the right password" if not user_1.is_valid_password(u_pwd) else "OK: Valid password check passed")
    print("is_valid_password should return False if it's not the right password" if user_1.is_valid_password("Fakepwd") else "OK: Invalid password check passed")
    print("is_valid_password should return False if compare with None" if user_1.is_valid_password(None) else "OK: None password check passed")
    print("is_valid_password should return False if compare with integer" if user_1.is_valid_password(89) else "OK: Integer password check passed")
    print("is_valid_password should return False if no password set before" if user_2.is_valid_password("No pwd") else "OK: No password set check passed")
