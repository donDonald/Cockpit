# protontricks (ERROR): Could not find configured Proton installation!
```

The error "protontricks (ERROR): Could not find configured Proton installation!" indicates that Protontricks cannot locate the necessary Proton files or prefixes that it needs to interact with. This can occur for several reasons:

    Game Not Launched with Proton:
    Protontricks relies on the game having been launched at least once with a specific Proton version through Steam. This action creates the necessary Wine prefix and configuration files that Protontricks then detects. Launching the game with Proton once allows Protontricks to identify and interact with its prefix.
    Incorrect Steam Library Paths:
    If your Steam library folders are not correctly configured or are located on external drives that Protontricks lacks access to, it might fail to find the Proton installations associated with those games. Ensure that all Steam library folders are properly set up within Steam and that Protontricks has the necessary permissions to access these locations. This is particularly relevant when using Flatpak versions of Protontricks, which might require explicit filesystem permissions (e.g., via Flatseal).
    Proton Installation Issues:
    While less common, a corrupted or incomplete Proton installation can also lead to this error. Verify the integrity of your Proton installation within Steam or consider reinstalling the specific Proton version if issues persist.
    Flatpak Specific Permissions:
    If you are running Protontricks as a Flatpak, it operates within a sandbox and might require additional permissions to access your Steam library folders or other parts of your filesystem. Tools like Flatseal can be used to grant these permissions.
```

Definetely Steam install protontricks vith flatpack:
```
find ~/ -name protontricks
...
/var/lib/flatpak/app/com.github.Matoking.protontricks/x86_64/stable/3f104e5492ab785c7572e5bffb67e58df1eed268922deeb987bdfbd5887e29f1/files/bin/protontricks
...
```

Steam prefixes location:/home/ptaranov/.local/share/Steam/steamapps/compatdata


Therefor have t resolve that permission issue metioned above.
Here is [solution](https://gamebanana.com/tuts/17166)

## Install Flatseal
https://flathub.org/en/apps/com.github.tchx84.Flatseal?ref=hackandslash.blog
