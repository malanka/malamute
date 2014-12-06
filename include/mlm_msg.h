/*  =========================================================================
    mlm_msg - The Malamute Protocol
    
    Codec header for mlm_msg.

    ** WARNING *************************************************************
    THIS SOURCE FILE IS 100% GENERATED. If you edit this file, you will lose
    your changes at the next build cycle. This is great for temporary printf
    statements. DO NOT MAKE ANY CHANGES YOU WISH TO KEEP. The correct places
    for commits are:

     * The XML model used for this code generation: mlm_msg.xml, or
     * The code generation script that built this file: zproto_codec_c
    ************************************************************************
    Copyright (c) the Contributors as noted in the AUTHORS file.       
    This file is part of the Malamute Project.                         
                                                                       
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.           
    =========================================================================
*/

#ifndef __MLM_MSG_H_INCLUDED__
#define __MLM_MSG_H_INCLUDED__

/*  These are the mlm_msg messages:

    CONNECTION_OPEN - Client opens a connection to the server. Client can ask for a mailbox
by specifying an address. If mailbox does not exist, server creates it.
Server replies with OK or ERROR.
        protocol            string      Constant "MALAMUTE"
        version             number 2    Protocol version 1
        address             string      Client address

    CONNECTION_PING - Client pings the server. Server replies with CONNECTION-PONG, or
ERROR with status COMMAND-INVALID if the client is not recognized
(e.g. after a server restart or network recovery).

    CONNECTION_PONG - Server replies to a client connection ping.

    CONNECTION_CLOSE - Client closes the connection. This is polite though not mandatory.
Server will reply with OK or ERROR.

    STREAM_WRITE - Client declares intention to write to a stream. If stream does not
exist, server creates it. A client can write to a single stream at
once. Server replies with OK or ERROR.
        stream              string      Name of stream

    STREAM_READ - Client opens a stream for reading, specifying a pattern to match
message subjects. An empty pattern matches everything. If the stream
does not exist, the server creates it. A client can read from many
streams at once. It can also read from the same stream many times,
with different patterns. Server replies with OK or ERROR.
        stream              string      Name of stream
        pattern             string      Match message subjects

    STREAM_SEND - Client publishes a message to the current stream. A stream message
has a subject, and a content of zero or more frames. Server does not
reply to this message. The subject is used to match messages to
readers. A reader will receive a given message at most once.
        subject             string      Message subject
        content             msg         Message body frames

    STREAM_DELIVER - Server delivers a stream message to a client. The delivered message
has the address of the original sending client, so clients can send
messages back to the original sender's mailbox if they need to.
        stream              string      Name of stream
        sender              string      Sending client address
        subject             string      Message subject
        content             msg         Message body frames

    MAILBOX_SEND - Client sends a message to a specified mailbox. Client does not open the
mailbox before sending a message to it. Server replies with OK when it
accepts the message, or ERROR if that failed. If the tracker is not
empty, the sender can expect a CONFIRM at some later stage, for this
message. Confirmations are asynchronous. If the message cannot be
delivered within the specified timeout (zero means infinite), the server
discards it and returns a CONFIRM with a TIMEOUT-EXPIRED status.
        address             string      Mailbox address
        subject             string      Message subject
        tracker             string      Message tracker
        timeout             number 4    Timeout, msecs, or zero
        content             msg         Message body frames

    MAILBOX_DELIVER - Server delivers a mailbox message to client. Note that client does not 
open its own mailbox for reading; this is implied in CONNECTION-OPEN.
If tracker is not empty, client must respond with CONFIRM when it
formally accepts delivery of the message, or if the server delivers
the same message a second time.
        sender              string      Sending client address
        address             string      Mailbox address
        subject             string      Message subject
        tracker             string      Message tracker
        content             msg         Message body frames

    SERVICE_SEND - Client sends a service request to a service queue. Server replies with
OK when queued, or ERROR if that failed. If the tracker is not
empty, the client can expect a CONFIRM at some later time.
Confirmations are asynchronous. If the message cannot be delivered
within the specified timeout (zero means infinite), the server
discards it and returns CONFIRM with a TIMEOUT-EXPIRED status.
        service             string      Service name
        subject             string      Message subject
        tracker             string      Message tracker
        timeout             number 4    Timeout, msecs, or zero
        content             msg         Message body frames

    SERVICE_OFFER - Worker client offers a named service, specifying a pattern to match
message subjects. An empty pattern matches anything. A worker can offer
many different services at once. Server replies with OK or ERROR.
        service             string      Service name
        pattern             string      Match message subjects

    SERVICE_DELIVER - Server delivers a service request to a worker client. If tracker
is not empty, worker must respond with CONFIRM when it accepts delivery
of the message. The worker sends replies to the request to the requesting
client's mailbox.
        sender              string      Sending client address
        service             string      Service name
        subject             string      Message subject
        tracker             string      Message tracker
        content             msg         Message body frames

    OK - Server replies with success status. Actual status code provides more
information. An OK always has a 2xx status code.
        status_code         number 2    3-digit status code
        status_reason       string      Printable explanation

    ERROR - Server replies with failure status. Actual status code provides more
information. An ERROR always has a 3xx, 4xx, or 5xx status code.
        status_code         number 2    3-digit status code
        status_reason       string      Printable explanation

    CREDIT - Client sends credit to allow delivery of messages. Until the client
sends credit, the server will not deliver messages. The client can send
further credit at any time. Credit is measured in number of messages.
Server does not reply to this message. Note that credit applies to all
stream, mailbox, and service deliveries.
        amount              number 2    Number of messages

    CONFIRM - Client confirms reception of a message, or server forwards this
confirmation to original sender. If status code is 300 or higher, this
indicates that the message could not be delivered.
        tracker             string      Message tracker
        status_code         number 2    3-digit status code
        status_reason       string      Printable explanation
*/

#define MLM_MSG_SUCCESS                     200
#define MLM_MSG_STORED                      201
#define MLM_MSG_DELIVERED                   202
#define MLM_MSG_NOT_DELIVERED               300
#define MLM_MSG_CONTENT_TOO_LARGE           301
#define MLM_MSG_TIMEOUT_EXPIRED             302
#define MLM_MSG_CONNECTION_REFUSED          303
#define MLM_MSG_RESOURCE_LOCKED             400
#define MLM_MSG_ACCESS_REFUSED              401
#define MLM_MSG_NOT_FOUND                   404
#define MLM_MSG_COMMAND_INVALID             500
#define MLM_MSG_NOT_IMPLEMENTED             501
#define MLM_MSG_INTERNAL_ERROR              502

#define MLM_MSG_CONNECTION_OPEN             1
#define MLM_MSG_CONNECTION_PING             2
#define MLM_MSG_CONNECTION_PONG             3
#define MLM_MSG_CONNECTION_CLOSE            4
#define MLM_MSG_STREAM_WRITE                5
#define MLM_MSG_STREAM_READ                 6
#define MLM_MSG_STREAM_SEND                 7
#define MLM_MSG_STREAM_DELIVER              8
#define MLM_MSG_MAILBOX_SEND                9
#define MLM_MSG_MAILBOX_DELIVER             10
#define MLM_MSG_SERVICE_SEND                11
#define MLM_MSG_SERVICE_OFFER               12
#define MLM_MSG_SERVICE_DELIVER             13
#define MLM_MSG_OK                          14
#define MLM_MSG_ERROR                       15
#define MLM_MSG_CREDIT                      16
#define MLM_MSG_CONFIRM                     17

#include <czmq.h>

#ifdef __cplusplus
extern "C" {
#endif

//  Opaque class structure
#ifndef MLM_MSG_T_DEFINED
typedef struct _mlm_msg_t mlm_msg_t;
#define MLM_MSG_T_DEFINED
#endif

//  @interface
//  Create a new empty mlm_msg
MLM_EXPORT mlm_msg_t *
    mlm_msg_new (void);

//  Destroy a mlm_msg instance
MLM_EXPORT void
    mlm_msg_destroy (mlm_msg_t **self_p);

//  Receive a mlm_msg from the socket. Returns 0 if OK, -1 if
//  there was an error. Blocks if there is no message waiting.
MLM_EXPORT int
    mlm_msg_recv (mlm_msg_t *self, zsock_t *input);

//  Send the mlm_msg to the output socket, does not destroy it
MLM_EXPORT int
    mlm_msg_send (mlm_msg_t *self, zsock_t *output);
    
//  Print contents of message to stdout
MLM_EXPORT void
    mlm_msg_print (mlm_msg_t *self);

//  Get/set the message routing id
MLM_EXPORT zframe_t *
    mlm_msg_routing_id (mlm_msg_t *self);
MLM_EXPORT void
    mlm_msg_set_routing_id (mlm_msg_t *self, zframe_t *routing_id);

//  Get the mlm_msg id and printable command
MLM_EXPORT int
    mlm_msg_id (mlm_msg_t *self);
MLM_EXPORT void
    mlm_msg_set_id (mlm_msg_t *self, int id);
MLM_EXPORT const char *
    mlm_msg_command (mlm_msg_t *self);

//  Get/set the address field
MLM_EXPORT const char *
    mlm_msg_address (mlm_msg_t *self);
MLM_EXPORT void
    mlm_msg_set_address (mlm_msg_t *self, const char *value);

//  Get/set the stream field
MLM_EXPORT const char *
    mlm_msg_stream (mlm_msg_t *self);
MLM_EXPORT void
    mlm_msg_set_stream (mlm_msg_t *self, const char *value);

//  Get/set the pattern field
MLM_EXPORT const char *
    mlm_msg_pattern (mlm_msg_t *self);
MLM_EXPORT void
    mlm_msg_set_pattern (mlm_msg_t *self, const char *value);

//  Get/set the subject field
MLM_EXPORT const char *
    mlm_msg_subject (mlm_msg_t *self);
MLM_EXPORT void
    mlm_msg_set_subject (mlm_msg_t *self, const char *value);

//  Get a copy of the content field
MLM_EXPORT zmsg_t *
    mlm_msg_content (mlm_msg_t *self);
//  Get the content field and transfer ownership to caller
MLM_EXPORT zmsg_t *
    mlm_msg_get_content (mlm_msg_t *self);
//  Set the content field, transferring ownership from caller
MLM_EXPORT void
    mlm_msg_set_content (mlm_msg_t *self, zmsg_t **msg_p);

//  Get/set the sender field
MLM_EXPORT const char *
    mlm_msg_sender (mlm_msg_t *self);
MLM_EXPORT void
    mlm_msg_set_sender (mlm_msg_t *self, const char *value);

//  Get/set the tracker field
MLM_EXPORT const char *
    mlm_msg_tracker (mlm_msg_t *self);
MLM_EXPORT void
    mlm_msg_set_tracker (mlm_msg_t *self, const char *value);

//  Get/set the timeout field
MLM_EXPORT uint32_t
    mlm_msg_timeout (mlm_msg_t *self);
MLM_EXPORT void
    mlm_msg_set_timeout (mlm_msg_t *self, uint32_t timeout);

//  Get/set the service field
MLM_EXPORT const char *
    mlm_msg_service (mlm_msg_t *self);
MLM_EXPORT void
    mlm_msg_set_service (mlm_msg_t *self, const char *value);

//  Get/set the status_code field
MLM_EXPORT uint16_t
    mlm_msg_status_code (mlm_msg_t *self);
MLM_EXPORT void
    mlm_msg_set_status_code (mlm_msg_t *self, uint16_t status_code);

//  Get/set the status_reason field
MLM_EXPORT const char *
    mlm_msg_status_reason (mlm_msg_t *self);
MLM_EXPORT void
    mlm_msg_set_status_reason (mlm_msg_t *self, const char *value);

//  Get/set the amount field
MLM_EXPORT uint16_t
    mlm_msg_amount (mlm_msg_t *self);
MLM_EXPORT void
    mlm_msg_set_amount (mlm_msg_t *self, uint16_t amount);

//  Self test of this class
MLM_EXPORT int
    mlm_msg_test (bool verbose);
//  @end

//  For backwards compatibility with old codecs
#define mlm_msg_dump        mlm_msg_print

#ifdef __cplusplus
}
#endif

#endif
