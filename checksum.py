#!/usr/bin/env python3
# calculate checksum for files
# Copyright 2018, Aswin Babu Karuvally

# import serious stuff
import zlib
import argparse
import sys
import sqlite3
import os


# read and return list of files
def read_file_list(file_list_path):
    try:
        file_list_file = open(file_list_path, "r")
        list_of_files = [line.rstrip() for line in file_list_file]
        file_list_file.close()
    except:
        print("error: unable to load list of files")
        sys.exit(0)

    return list_of_files


# generate checksum of files
def generate_checksum(list_of_files):
    checksums = {}

    for file_path in list_of_files:
        try:
            input_file = open(file_path, "rb")
            input_file_data = input_file.read()

            checksums.update({file_path: zlib.crc32(input_file_data)})
            input_file.close()
        except:
            print("error: unable to read", file_path)
            sys.exit(1)

    return checksums


# setup the sqlite database
def setup_database(database_path):
    connection = sqlite3.connect(database_path)
    
    connection.executescript("""
    create table file_checksum(
        id integer primary key autoincrement not null,
        file_path text unique,
        checksum text not null
    """)

    connection.close()


# the main function
def main():
    # read the run-time arguments
    parser = argparse.ArgumentParser(description =
    "Looks for changes in files")
    
    parser.add_argument("file_list", help = "specify path to file list")
    arguments = parser.parse_args()

    # read list of files
    list_of_files = read_file_list(arguments.file_list)

    # generate crc of each file
    checksums = generate_checksum(list_of_files)

    # check if file already has hash in database
    database_path = os.path.join("home", os.getlogin(), ".file_checksum.db")
    if not os.path.exists(database_path):
        setup_database(database_path)

    # if not, create the entry in db
    # cross check both hashes
    # alert user if change in hash


# run the main function
main()
