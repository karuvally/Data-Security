#!/usr/bin/env python3
# calculate checksum for files
# Copyright 2018, Aswin Babu Karuvally

# import serious stuff
import zlib
import argparse


# read and return list of files
def read_file_list(file_list_path):
    try:
        file_list_file = open(file_list_path, "r")
        list_of_files = [line.rstrip() for line in file_list_file]
        file_list_file.close()
    except:
        print("error: unable to load list of files")

    return list_of_files


# generate checksum of files


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
    crc_list = []

    # check if file already has hash in database
    # if not, create the entry in db
    # cross check both hashes
    # alert user if change in hash


# run the main function
main()
