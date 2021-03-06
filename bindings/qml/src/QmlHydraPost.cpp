/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/

#include "QmlHydraPost.h"


///
//  Recalculate the post ID based on subject, timestamp, parent id, MIME
//  type, and content digest, and return post ID to caller.             
const QString QmlHydraPost::ident () {
    return QString (hydra_post_ident (self));
};

///
//  Return the post subject, if set
const QString QmlHydraPost::subject () {
    return QString (hydra_post_subject (self));
};

///
//  Return the post timestamp
const QString QmlHydraPost::timestamp () {
    return QString (hydra_post_timestamp (self));
};

///
//  Return the post parent id, or empty string if not set
const QString QmlHydraPost::parentId () {
    return QString (hydra_post_parent_id (self));
};

///
//  Return the post MIME type, if set
const QString QmlHydraPost::mimeType () {
    return QString (hydra_post_mime_type (self));
};

///
//  Return the post content digest
const QString QmlHydraPost::digest () {
    return QString (hydra_post_digest (self));
};

///
//  Return the post content location
const QString QmlHydraPost::location () {
    return QString (hydra_post_location (self));
};

///
//  Return the post content size
size_t QmlHydraPost::contentSize () {
    return hydra_post_content_size (self);
};

///
//  Return the post content as a string. Returns NULL if the MIME type is      
//  not "text/plain". The caller must destroy the string when finished with it.
QString QmlHydraPost::content () {
    char *retStr_ = hydra_post_content (self);
    QString retQStr_ = QString (retStr_);
    free (retStr_);
    return retQStr_;
};

///
//  Set the post parent id, which must be a valid post ID
void QmlHydraPost::setParentId (const QString &parentId) {
    hydra_post_set_parent_id (self, parentId.toUtf8().data());
};

///
//  Set the post MIME type
void QmlHydraPost::setMimeType (const QString &mimeType) {
    hydra_post_set_mime_type (self, mimeType.toUtf8().data());
};

///
//  Set the post content to a text string. Recalculates the post digest from
//  from the new content value. Sets the MIME type to text/plain.           
void QmlHydraPost::setContent (const QString &content) {
    hydra_post_set_content (self, content.toUtf8().data());
};

///
//  Set the post content to a chunk of data. Recalculates the post digest 
//  from the chunk contents. Takes ownership of the chunk. The data is not
//  stored on disk until you call hydra_post_save.                        
void QmlHydraPost::setData (const void *data, size_t size) {
    hydra_post_set_data (self, data, size);
};

///
//  Set the post content to point to a specified file. The file must exist. 
//  Recalculates the post digest from the file contents. Returns 0 if OK, -1
//  if the file was unreadable.                                             
int QmlHydraPost::setFile (const QString &location) {
    return hydra_post_set_file (self, location.toUtf8().data());
};

///
//  Save the post to disk under the specified filename. Returns 0 if OK, -1 
//  if the file could not be created. Posts are always stored in the "posts"
//  subdirectory of the current working directory. Note: for internal use   
//  only.                                                                   
int QmlHydraPost::save (const QString &filename) {
    return hydra_post_save (self, filename.toUtf8().data());
};

///
//  Fetch a chunk of content for the post. The caller specifies the size and 
//  offset of the chunk. A size of 0 means all content, which will fail if   
//  there is insufficient memory available. The caller must destroy the chunk
//  when finished with it.                                                   
zchunk_t *QmlHydraPost::fetch (size_t size, size_t offset) {
    return hydra_post_fetch (self, size, offset);
};

///
//  Encode a post metadata to a hydra_proto message
void QmlHydraPost::encode (hydra_proto_t *proto) {
    hydra_post_encode (self, proto);
};

///
//  Duplicate a post instance. Does not create a new post on disk; this
//  provides a second instance of the same post item.                  
QmlHydraPost *QmlHydraPost::dup () {
    QmlHydraPost *retQ_ = new QmlHydraPost ();
    retQ_->self = hydra_post_dup (self);
    return retQ_;
};

///
//  Print the post file to stdout
void QmlHydraPost::print () {
    hydra_post_print (self);
};


QObject* QmlHydraPost::qmlAttachedProperties(QObject* object) {
    return new QmlHydraPostAttached(object);
}


///
//  Load post from the specified filename. Posts are always read from the    
//  "posts" subdirectory of the current working directory. Returns a new post
//  instance if the file could be loaded, else returns null.                 
QmlHydraPost *QmlHydraPostAttached::load (const QString &filename) {
    QmlHydraPost *retQ_ = new QmlHydraPost ();
    retQ_->self = hydra_post_load (filename.toUtf8().data());
    return retQ_;
};

///
//  Create a new post from a hydra_proto HEADER-OK message.
QmlHydraPost *QmlHydraPostAttached::decode (hydra_proto_t *proto) {
    QmlHydraPost *retQ_ = new QmlHydraPost ();
    retQ_->self = hydra_post_decode (proto);
    return retQ_;
};

///
//  Self test of this class
void QmlHydraPostAttached::test (bool verbose) {
    hydra_post_test (verbose);
};

///
//  Create a new post
QmlHydraPost *QmlHydraPostAttached::construct (const QString &subject) {
    QmlHydraPost *qmlSelf = new QmlHydraPost ();
    qmlSelf->self = hydra_post_new (subject.toUtf8().data());
    return qmlSelf;
};

///
//  Destroy the post
void QmlHydraPostAttached::destruct (QmlHydraPost *qmlSelf) {
    hydra_post_destroy (&qmlSelf->self);
};

/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/
