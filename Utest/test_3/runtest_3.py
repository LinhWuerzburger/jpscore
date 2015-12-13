#!/usr/bin/env python
import os
import sys
from sys import *
sys.path.append(os.path.abspath(os.path.dirname(sys.path[0])))
from JPSRunTest import JPSRunTestDriver
from utils import *

__author__ = 'Oliver Schmidts'


def runtest3(inifile, trajfile):
    maxtime = get_maxtime(inifile)
    fps, N, traj = parse_file(trajfile)
    evac_time = (max(traj[:, 1]) - min(traj[:, 1])) / float(fps)
    if evac_time > maxtime*0.5:
        logging.info("%s exits with FAILURE evac_time = %f (maxtime =  %f)" % (argv[0], evac_time, maxtime))
        exit(FAILURE)
    else:
        logging.info("evac_time = %f (maxtime =  %f)" % (evac_time, maxtime))


if __name__ == "__main__":
    test = JPSRunTestDriver(3, argv0=argv[0], testdir=sys.path[0])
    test.run_test(testfunction=runtest3)
    logging.info("%s exits with SUCCESS" % (argv[0]))
    exit(SUCCESS)