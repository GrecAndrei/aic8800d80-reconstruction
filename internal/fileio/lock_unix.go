//go:build linux || darwin

package fileio

import (
	"fmt"
	"os"
	"syscall"
)

type FileLock struct {
	f *os.File
}

func AcquireFileLock(path string) (*FileLock, error) {
	f, err := os.OpenFile(path, os.O_CREATE|os.O_RDWR, 0o644)
	if err != nil {
		return nil, fmt.Errorf("open lock %s: %w", path, err)
	}
	if err := syscall.Flock(int(f.Fd()), syscall.LOCK_EX); err != nil {
		_ = f.Close()
		return nil, fmt.Errorf("lock %s: %w", path, err)
	}
	return &FileLock{f: f}, nil
}

func (l *FileLock) Release() error {
	if l == nil || l.f == nil {
		return nil
	}
	errUnlock := syscall.Flock(int(l.f.Fd()), syscall.LOCK_UN)
	errClose := l.f.Close()
	if errUnlock != nil {
		return errUnlock
	}
	return errClose
}
