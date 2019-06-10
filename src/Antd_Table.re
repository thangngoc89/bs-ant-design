[@bs.module "antd/lib/table"]
external table: ReasonReact.reactClass = "default";

[%bs.raw {|require("antd/lib/table/style")|}];

[@bs.deriving abstract]
type jsProps('a, 'b, 'c, 'd) = {
  [@bs.optional]
  dataSource: array(Js.t('a)),
  [@bs.optional]
  columns: array('b),
  [@bs.optional]
  prefixCls: string,
  [@bs.optional]
  useFixedHeader: bool,
  [@bs.optional]
  rowSelection: Js.Json.t,
  [@bs.optional]
  className: string,
  [@bs.optional]
  size: string,
  [@bs.optional]
  loading: bool,
  [@bs.optional]
  pagination: Js.t('d),
  [@bs.optional]
  bordered: bool,
  [@bs.optional]
  onChange: Js.t('c) => unit,
  [@bs.optional]
  locale: Js.Json.t,
  [@bs.optional]
  dropdownPrefixCls: string,
};

let make =
    (
      ~dataSource=?,
      ~columns=?,
      ~prefixCls=?,
      ~useFixedHeader=?,
      ~rowSelection=?,
      ~className=?,
      ~size=?,
      ~loading=?,
      ~pagination=?,
      ~bordered=?,
      ~onChange=?,
      ~locale=?,
      ~dropdownPrefixCls=?,
      children,
    ) => {
  ReasonReact.wrapJsForReason(
    ~reactClass=table,
    ~props=
      jsProps(
        ~dataSource?,
        ~columns?,
        ~prefixCls?,
        ~useFixedHeader?,
        ~rowSelection?,
        ~className?,
        ~size?,
        ~loading?,
        ~pagination?,
        ~bordered?,
        ~onChange?,
        ~locale?,
        ~dropdownPrefixCls?,
        (),
      ),
    children,
  );
};