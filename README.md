Unicorn USB V.2 driver for Linux
================================

CHANGES:
--------

Updated by Mateusz Machalica <mateuszmachalica@gmail.com> to work with 2.6.35 Linux kernel (tested on ArchLinux patched kernel).
Changes in eth and usb driver due to revised linux ethernet drivers api.
No plans for future support (as of Sep 2010), feel free to adopt.

INTRODUCTION:
-------------

The software for the UNICORN II ADSL USB card consists of one loadable driver, the unicorn_usb_eth.ko.The unicorn_atm driver is a standard Linux ATM driver, that performs segmentation and reassembly (SAR) and flow control. The unicorn_usb driver contains the ADSL modem software and hardware related functions. 

The software has been tested with the Linux Kernel 2.6.3 and 2.6.16-16 kernel.

End-to-End Connection
---------------------

To establish the PPP connection you should install the rp-pppoe-x.x.x package. Once rp-pppoe-x.x.x package is installed you can start the following procedure to establish the connection. 

	For a PPPoA connection:
	-----------------------
	# modprobe unicorn_usb_eth ActivationMode=3 VPI=8 VCI=40 PROTOCOL=pppoatm ENCAPS=vc-encaps
	# adsl-connect.

	
	Note: VPI, VCI and ENCAPS are as per service provider's guide lines
        
        For a PPPoE connection:
        -----------------------
	# modprobe unicorn_usb_eth ActivationMode=3 VPI=8 VCI=41 PROTOCOL=pppoe ENCAPS=llc-encaps
	# adsl-connect.

	
        Note: VPI, VCI and ENCAPS are as per service provider's guide lines
        
	For a BRIDGED (RFC2684) connection:
	----------------------------------
	# modprobe unicorn_usb_eth ActivationMode=3 VPI=7 VCI=33 PROTOCOL=br2684 ENCAPS=llc-encaps
	# ifconfig dsl0 138.200.200.8 netmask 255.255.255.0


	Note: VPI, VCI, ENCAPS and IP address are as per service provider's guide lines
	
        For a ROUTED (RFC2684) connection you can do this:
	--------------------------------------------------
	# modprobe unicorn_usb_eth ActivationMode=3 VPI=10 VCI=45 PROTOCOL=ipoatm ENCAPS=vc-encaps
	# ifconfig dsl0 155.120.120.8 netmask 255.255.255.0

	
        Note: VPI, VCI, ENCAPS and IP address are as per service provider's guide lines
                                               
                                               
To have the connection start at boot time the commands mentioned should be added to the end of /etc/rc.d/rc.local.

Check in the syslog that the drivers are started OK. The ADSL line should come up automatically. SHOWTIME in the log or in the status means that ADSL connection is up and ATM cells may be transmitted and received.

Depending on your network setup, you will need additional software as with any other ADSL ATM card. For bridged ethernet (RFC2684), the br2684.o module and brctl is needed. For PPPoE, any pppoe client over the bridged interface (nas0) should work (Roaring Penguin pppoe client has been tested).

Bridged (RFC2684) and PPP over Ethernet:
Depending on your kernel, you may need to patch the kernel and enable the option "RFC1483/2684 Bridged protcols" under "Networking options". Also ATM support needs to be enabled. Also the user space daemon "brctl" is needed.

PPP over ATM:
For PPP over ATM, the module pppoatm.o is needed, together with the pppd plugin pppoatm.so and a version of pppd that supports plugins.
Currently version ppp-2.4.0b2 supports PPPoATM plugins. A patched version ready for PPPoATM can be found at http://www.sourceforge.net/.

PPPoATM specific pppd options:
llc-encaps: use LLC encapsulation for PPPoATM
vc-encaps: use VC multiplexing for PPPoATM (default)

MODULE PARAMETERS:
-----------------

The module parameters can be passed to the module when the module is loaded (insmod or modprobe).

ActivationMode: This parameter sets in what mode the ADSL modem should be activated.
ANSI mode is 1, G.lite is 2, G.dmt is 4 and MULTI mode is 3.
If you know what mode your DSLAM operates in, use this mode. If not select either
ANSI or MULTI mode.

DownstreamRate: The maximum downstream rate in Kbit/sec.

AutoActivation: Set this to 1 if your ADSL modem to start automatically (default 1).

DebugLevel: To debug the driver, set this to a value different from 0 and enable DEBUG
when compiling.

LedScenario: Select the LED behaviour 0 (Brussels LED), 1 (Antwerp LED), 2 (Ghent LED). Default 1.

Loopbackmode: Loopback ATM cells in digital chip 0(disable), 1(enable). Default 0.

RetryTime: Time modem tries to reach showtime (default 2000 msec).

VPI/VCI: Enter VPI and VCI as for DSLAM configuration.

ENCAPS: Encapslations( llc-encaps and vc-encaps), default llc-encaps.

PROTOCOL: Protocol for connection 
	pppoatm for PPPOA, pppoe for PPPoE, br2684 for RFC2684_BRIDGED, ipoatm for RFC2684_ROUTED. Default RFC2684_BRIDGED.

RELEASE NOTES:
--------------

Version USB-ADSL-UNICORN-2.6.35-0
.  Works with linux kernel 2.6.35, tested also with ArchLinux patched

Version USB-APL-7-2.0-0.2.0.6
.  Unicorn_usb_eth.ko works in all alternate USB settings (Bulk, ISO)
.  Control & status application upgraded for Unicorn II

Version  USB-APL-7-2.0-0.2.0.7
. Code clean up action: old stuff has been removed

Version  USB-APL-7-2.0-0.2.0.8
. Global destructors are called when Unicorn driver is removed
. Default Modem Software activation mode is 3 (Multimode Annex A)


Version  USB-APL-7-2.0-0.2.0.10
. Improved FTP upload throughput

Version  USB-APL-7-2.0-0.2.0.11
. Annex B and BDT support in driver and control & status application
. Improved build procedure

Version  USB-APL-7-2.0-0.2.0.12
. this version released with new modem software USB-AML-7-2.0-0.2.0.41

Version  USB-APL-7-2.0-0.2.0.13
. removed PCI stuff
. implimented modules_install option
. README file updated

Version  USB-APL-7-2.0-0.2.0.14
. removed unnecessary files

Version  USB-APL-7-2.0-0.2.0.15
. fix for modem plug in/out crash
. new modem software USB-AML-7-2.0-0.2.0.50

Version  USB-APL-7-2.0-0.2.0.16
. new modem software USB-AML-7-2.0-0.2.0.55

Version  USB-APL-7-2.0-0.2.0.17
 new modem software USB-AML-7-2.0-0.2.0.66
 Under CSA Config tab updated to show the PROTOCOL name when driver installed
Version  USB-APL-7-2.0-0.2.0.18
 modem software USB-AML-7-2.0-0.2.0.66 + built in linux libs
 Under CSA Source to compile on fedora Core 2
Version  USB-APL-7-2.0-0.2.0.18
 modem software USB-AML-7-2.0-0.2.0.66 + built in linux libs
 Under CSA Source to compile on fedora Core 2
Version  USB-APL-7-2.0-0.2.0.19
 Updated CSA

Version  USB-APL-7-2.0-0.2.0.20
 CSA window is configured
 supports kernel till 2.6.16-16

