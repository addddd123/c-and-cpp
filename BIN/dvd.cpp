#include <windows.h>
#include <winioctl.h>
#include <stdio.h>

#define LOCK_TIMEOUT  10000       // 10 Seconds
#define LOCK_RETRIES  20

HANDLE OpenVolume(TCHAR cDriveLetter)
{
    HANDLE hVolume;
    UINT   uDriveType;
    char   szVolumeName[8];
    char   szRootName[5];
    DWORD  dwAccessFlags;
   
    sprintf(szRootName, "%c:\\", cDriveLetter);

    uDriveType = GetDriveType(szRootName);
    switch(uDriveType) {
      case DRIVE_REMOVABLE:
           dwAccessFlags = GENERIC_READ | GENERIC_WRITE;
           break;
      case DRIVE_CDROM:
           dwAccessFlags = GENERIC_READ;
           break;
      default:
           printf("Cannot eject.  Drive type is incorrect.\n");
           return INVALID_HANDLE_VALUE;
    }

    sprintf(szVolumeName, "\\\\.\\%c:", cDriveLetter);

    hVolume = CreateFile( szVolumeName,
                          dwAccessFlags,
                          FILE_SHARE_READ | FILE_SHARE_WRITE,
                          NULL,
                          OPEN_EXISTING,
                          0,
                          NULL );

    if (hVolume == INVALID_HANDLE_VALUE)
      printf("CreateFile error %d\n", GetLastError());
    return hVolume;
}

BOOL CloseVolume(HANDLE hVolume)
{
    return CloseHandle(hVolume);
}

BOOL LockVolume(HANDLE hVolume)
{
    DWORD dwBytesReturned;
    DWORD dwSleepAmount;
    int nTryCount;

    dwSleepAmount = LOCK_TIMEOUT / LOCK_RETRIES;

    // Do this in a loop until a timeout period has expired
    for (nTryCount = 0; nTryCount < LOCK_RETRIES; nTryCount++) {
      if (DeviceIoControl(hVolume,
                          FSCTL_LOCK_VOLUME,
                          NULL, 0,
                          NULL, 0,
                          &dwBytesReturned,
                          NULL))
         return TRUE;

      Sleep(dwSleepAmount);
    }
    return FALSE;
}

BOOL DismountVolume(HANDLE hVolume)
{
    DWORD dwBytesReturned;

    return DeviceIoControl( hVolume,
                            FSCTL_DISMOUNT_VOLUME,
                            NULL, 0,
                            NULL, 0,
                            &dwBytesReturned,
                            NULL);
}

BOOL PreventRemovalOfVolume(HANDLE hVolume, BOOL fPreventRemoval)
{
    DWORD dwBytesReturned;
    PREVENT_MEDIA_REMOVAL PMRBuffer;

    PMRBuffer.PreventMediaRemoval = fPreventRemoval;

    return DeviceIoControl( hVolume,
                            IOCTL_STORAGE_MEDIA_REMOVAL,
                            &PMRBuffer, sizeof(PREVENT_MEDIA_REMOVAL),
                            NULL, 0,
                            &dwBytesReturned,
                            NULL);
}

AutoEjectVolume(HANDLE hVolume)
{
    DWORD dwBytesReturned;

    return DeviceIoControl( hVolume,
                            IOCTL_STORAGE_EJECT_MEDIA,
                            NULL, 0,
                            NULL, 0,
                            &dwBytesReturned,
                            NULL);
}

BOOL EjectVolume(TCHAR cDriveLetter)
{
    HANDLE hVolume;

    BOOL fRemoveSafely = FALSE;
    BOOL fAutoEject = FALSE;

    hVolume = OpenVolume(cDriveLetter);
    if (hVolume == INVALID_HANDLE_VALUE)
      return FALSE;

    // Lock and dismount the volume.
    if (LockVolume(hVolume) && DismountVolume(hVolume)) {
      fRemoveSafely = TRUE;
      // Set prevent removal to false and eject the volume.
      if (PreventRemovalOfVolume(hVolume, FALSE) && AutoEjectVolume(hVolume))
        fAutoEject = TRUE;
    }

    // Close the volume so other processes can use the drive.
    if (!CloseVolume(hVolume))
      return FALSE;

    if (fAutoEject)
      printf("Media in Drive %c has been ejected safely.\n", cDriveLetter);
    else {
      if (fRemoveSafely)
        printf("Media in Drive %c can be safely removed.\n", cDriveLetter);
    }
    return TRUE;
}

void Usage()
{
    printf("Usage: Eject <drive letter>\n\n");
    return ;
}

void main(int argc, char * argv[])
{
    if (argc != 2) {
      Usage();
      return ;
    }

    if (!EjectVolume(argv[1][0]))
      printf("Failure ejecting drive %c.\n", argv[1][0]);

    return ;
}

