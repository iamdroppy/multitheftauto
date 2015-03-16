![http://www.multitheftauto.com/images/logosmall.png](http://www.multitheftauto.com/images/logosmall.png)

## Introduction ##
Multi Theft Auto (MTA) is a software project that adds network play functionality to Rockstar North's [Grand Theft Auto](http://en.wikipedia.org/wiki/Grand_Theft_Auto_(series)) game series, in which this functionality is not originally found. It is a unique modification that incorporates an extendable network play element into a proprietary commercial single-player PC game.

Multi Theft Auto is based on code injection and hooking techniques whereby the game is manipulated without altering any original files supplied with the game. The software functions as a game engine that installs itself as an extension of the original game, adding core functionality such as networking and GUI rendering while exposing the original game's engine functionality through a scripting language.

Originally founded back in early 2003 as an experimental piece of C/C++ software, Multi Theft Auto has since grown into an advanced multiplayer platform for gamers and third-party developers. Our software provides a minimal sandbox style gameplay that can be extended through the Lua scripting language in many ways, allowing servers to run custom created game modes with custom content for up to hundreds of online players.

Third party content is made possible through the addition of the Lua scripting language in both the server hosting the game (e.g. providing functionality for a specific game mode), as well as the client playing the game (e.g. providing a graphical front end or user-specific local content to the game mode). Different scripts can then be run in parallel on either of these, communicating to each other through the use of events.

Formerly a closed-source project, we have migrated to open-source to encourage other developers to contribute as well as showing insight into our project's source code and design for educational reasons.

![http://www.mtasa.com/images/about1small.png](http://www.mtasa.com/images/about1small.png) ![http://www.mtasa.com/images/c_yougofirst.png](http://www.mtasa.com/images/c_yougofirst.png)

Head over to the [Multi Theft Auto website](http://www.multitheftauto.com/) for more information.

## Development ##
The status of our nightly builds can be seen below. For more information about these builds, head over to our [Nightly Builds](http://nightly.mtasa.com) page.

&lt;wiki:gadget url="http://www.mtasa.com/gadget/nightly.xml" height="210" width="610" border="0" /&gt;

We encourage anyone that is interested in participating in development to contribute! Our code is structured and easy to get around with. We offer our [own bug tracker](http://bugs.mtasa.com/) that contains bugs and feature reports and also allows any developer to submit their own patches. These patches will then be reviewed by us.

Next to a bug tracker, we also offer public access to our nightly build server which compiles a daily build of the latest revision.

All development stuff is available through your personal account at our [Multi Theft Auto community](http://community.mtasa.com/) website.

For the latest build, please head over to the [NightlyBuilds](NightlyBuilds.md) page for more information.

### Structure ###
Our project is divided into different sub-projects, which cohesively give MTA an overall functionality:

  * **blue**: This is the main component for adding multiplayer into GTA, and has it's own modularized structure.  Please see the [mtasa-blue project](http://code.google.com/p/mtasa-blue/) for further information.
  * **resources**: Resources are essentially packages which contain Lua scripts which are used to extend MTA's sandbox.  Without resources installed into the server, MTA can be regarded as a 'blank slate' - therefore it is essential that resources are used to build upon this.  The official resource pack can be found at the [resources project](http://code.google.com/p/multitheftauto-resources/), which adds various gamemodes and essential utilities required to run an MTA server..

### Discussion ###
Discussion about the development of this project can be done through our bug tracker or our IRC channel at GTAnet. Our IRC channel _#mta_ can be reached through our own GTAnet server _irc.multitheftauto.com_ or _irc.gtanet.com_.

We also have our forums available at http://forum.mtasa.com.

### Verification ###
All our source code available through this project page is licensed under the GPLv3 license. This excludes any dependencies and our _net modules_ for both the client and server: these are still covered under our proprietary license. These modules have been excluded because of reasons involving security and cheating, but contain only a minimal amount of code.

Our dedicated servers have the option of verifying users on connect, based on their serial number and Multi Theft Auto community username. This serial/username combination is queried through the master server, and the user is accepted unless the combination is invalid. Dedicated servers with verification can then ban users on their serial and username instead of only on IP-address, ensuring that people can be banned regardless of those that keep changing their IP-address.

Only a client running a Multi Theft Auto version that is released through this website or through our nightly build service generates a serial number. In other words, developer builds that are built manually by anyone will not be able to join servers that have serial verification turned on. For obvious reasons of course, as we would like to minimize the problem of people cheating through source code modifications.

![http://www.mtasa.com/images/c_baronshooters.png](http://www.mtasa.com/images/c_baronshooters.png) ![http://www.mtasa.com/images/c_bigpeds.png](http://www.mtasa.com/images/c_bigpeds.png) ![http://www.mtasa.com/images/c_stuntplanewoman.png](http://www.mtasa.com/images/c_stuntplanewoman.png)

## In practice ##
As a quick introduction to show you what's possible with our software, we have made a series of videos featuring various concept scripts (game modes) created by Lua developers that are working with us on this project.

These videos will show you a glimpse of the capabilities that our embedded scripting engine has over the actual game. Mind that all the necessary logic required to manipulate the objects and synchronizing them over the server has been implemented by our software and is accessible to any third party developer through a Lua virtual machine that runs on both the client and server.

&lt;wiki:gadget url="http://www.mtasa.com/gadget/crap.xml" height="400" width="610" border="0" /&gt;

Grand Theft Auto and all related trademarks are © Rockstar North 1997-2009.