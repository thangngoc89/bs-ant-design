[@bs.module]
external localeProvider : ReasonReact.reactClass = "antd/lib/locale-provider";

[%bs.raw {|require("antd/lib/locale-provider/style")|}];

module Locale = {
  module Table = {
    [@bs.deriving abstract]
    type t =
      pri {
        filterTitle: string,
        filterConfirm: string,
        filterReset: string,
        emptyText: string,
        selectAll: string,
        selectInvert: string,
      };
  };

  module Modal = {
    [@bs.deriving abstract]
    type t =
      pri {
        okText: string,
        cancelText: string,
        justOkText: string,
      };
  };

  module PopConfirm = {
    [@bs.deriving abstract]
    type t =
      pri {
        okText: string,
        cancelText: string,
      };
  };

  module Transfer = {
    [@bs.deriving abstract]
    type t =
      pri {
        titles: array(string),
        notFoundContent: string,
        searchPlaceholder: string,
        itemUnit: string,
        itemsUnit: string,
      };
  };

  module Select = {
    [@bs.deriving abstract]
    type t = pri {notFoundContent: string};
  };

  module Upload = {
    [@bs.deriving abstract]
    type t =
      pri {
        uploading: string,
        removeFile: string,
        uploadError: string,
        previewFile: string,
      };
  };

  [@bs.deriving abstract]
  type t =
    pri {
      locale: string,
      [@bs.as "Pagination"]
      pagination: Pagination.Locale.t,
      [@bs.as "DatePicker"]
      datePicker: Antd_DatePicker.Locale.t,
      [@bs.as "TimePicker"]
      timePicker: Antd_TimePicker.Locale.t,
      [@bs.as "Calendar"]
      calendar: Antd_Calendar.Locale.t,
      [@bs.as "Table"]
      table: Table.t,
      [@bs.as "Modal"]
      modal: Modal.t,
      [@bs.as "Popconfirm"]
      popConfirm: PopConfirm.t,
      [@bs.as "Transfer"]
      transfer: Transfer.t,
      [@bs.as "Select"]
      select: Select.t,
      [@bs.as "Upload"]
      upload: Upload.t,
    };
};

[@bs.obj] external makeProps : (~locale: Locale.t) => _ = "";

let make = (~locale, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=localeProvider,
    ~props=makeProps(~locale),
    children,
  );