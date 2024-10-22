import os

FILES_TO_COG = [
    'cmake/file_lists.cmake'
]

if __name__ == '__main__':
    for f in FILES_TO_COG:
        retcode = os.system(f"cog --check {f}")
        if retcode != 0:
            os.system(f"cog -r {f}")
